#ifndef CORE_SERVICE_HPP_
#define CORE_SERVICE_HPP_

#include <memory>

#include <spdlog/logger.h>

namespace config
{
class Config;
}

namespace core
{

class CommandLineArguments;

class Service final
{
public:
	int run(const CommandLineArguments& cmd_line) noexcept;

private:
	std::shared_ptr< spdlog::logger > m_logger{};

	void init_logging();
	void apply_command_line(const CommandLineArguments& cmd_line);
	void apply_config(const config::Config& conf);
};

} // namespace core

#endif // CORE_SERVICE_HPP_