#ifndef CORE_SERVICE_HPP_
#define CORE_SERVICE_HPP_

#include <memory>

#include <spdlog/logger.h>

namespace core
{

class CommandLineArguments;

class Service final
{
public:
	int run(const CommandLineArguments& cmd_line) noexcept;

private:
	std::shared_ptr< spdlog::logger > m_logger{};

	void init_logging(const bool verbose);
};

} // namespace core

#endif // CORE_SERVICE_HPP_