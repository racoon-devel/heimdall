#include "command_line.hpp"

#include <cxxopts.hpp>

namespace
{
auto create_parser()
{
	using namespace cxxopts;
	Options options("Heimdall");

	options.add_options()("v,verbose", "Verbose log output")(
		"V,version", "Print version")("help", "Print help")(
		"c,config", "Path to config file",
		value< std::string >()->default_value("/etc/heimdall/config.json"));

	return options;
}

} // namespace

namespace core
{

CommandLineArguments::CommandLineArguments(int argc, char** argv)
{
	auto options = create_parser();

	auto parsed   = options.parse(argc, argv);
	m_help        = parsed.count("help") != 0;
	m_version     = parsed.count("version") != 0;
	m_verbose     = parsed.count("verbose") != 0;
	m_config_path = parsed["config"].as< std::string >();
}

std::string CommandLineArguments::help() const
{
	return create_parser().help();
}

} // namespace core