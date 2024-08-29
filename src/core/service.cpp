#include "service.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <memory>
#include <utility>

#include <spdlog/common.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

int Service::run([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
try
{
	init_logging();

	SPDLOG_INFO("Service started");
	return EXIT_SUCCESS;
}
catch (const std::exception& e)
{
	SPDLOG_CRITICAL("Unhandled exception: {}", e.what());
	return EXIT_FAILURE;
}
catch (...)
{
	SPDLOG_CRITICAL("Unhandled unknown exception occurs");
	return EXIT_FAILURE;
}

void Service::init_logging()
try
{
	auto colored_sink =
		std::make_shared< spdlog::sinks::stderr_color_sink_mt >();
	auto logger = std::make_shared< spdlog::logger >("override_default_logger",
													 colored_sink);

	logger->set_level(spdlog::level::debug);
	logger->set_pattern("[%d %b %H:%M:%S %e][t:%t][%s:%#][%^%l%$] %v");

	spdlog::set_default_logger(logger);
	m_logger = std::move(logger);
}
catch (const std::exception& e)
{
	std::cerr << "Initialize log failed: " << e.what() << std::endl;
	throw;
}
