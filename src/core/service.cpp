#include "service.hpp"

#include <cstdlib>
#include <exception>
#include <memory>
#include <utility>

#include <fmt/core.h>
#include <spdlog/common.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "command_line.hpp"

namespace core
{

int Service::run(const CommandLineArguments& cmd_line) noexcept
try
{
	init_logging(cmd_line.verbose());

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

void Service::init_logging(const bool verbose)
try
{
	auto colored_sink =
		std::make_shared< spdlog::sinks::stderr_color_sink_mt >();
	auto logger = std::make_shared< spdlog::logger >("override_default_logger",
													 colored_sink);

	verbose ? logger->set_level(spdlog::level::debug)
			: logger->set_level(spdlog::level::info);
	logger->set_pattern("[%d %b %H:%M:%S %e][t:%t][%s:%#][%^%l%$] %v");

	spdlog::set_default_logger(logger);
	m_logger = std::move(logger);
}
catch (const std::exception& e)
{
	fmt::print(stderr, "Initialize log failed: {}\n", e.what());
	throw;
}

} // namespace core
