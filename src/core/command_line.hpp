#ifndef CORE_COMMAND_LINE_HPP_
#define CORE_COMMAND_LINE_HPP_

#include <string>

namespace core
{

class CommandLineArguments final
{
public:
	CommandLineArguments(int argc, char** argv);

	bool verbose() const noexcept { return m_verbose; }
	bool need_version() const noexcept { return m_version; }
	bool need_help() const noexcept { return m_help; }

	std::string config_path() const { return m_config_path; }
	std::string help() const;

private:
	bool        m_verbose{false};
	bool        m_version{false};
	bool        m_help{false};
	std::string m_config_path{};
};

} // namespace core

#endif // CORE_COMMAND_LINE_HPP_