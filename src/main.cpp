#include <cstdlib>
#include <exception>
#include <memory>

#include <fmt/core.h>

#include "core/command_line.hpp"
#include "core/service.hpp"

int main(int argc, char** argv)
{
	fmt::println("Heimdall v{}", PROJECT_VERSION);

	std::unique_ptr< core::CommandLineArguments > cmd_line;

	try
	{
		cmd_line = std::make_unique< core::CommandLineArguments >(argc, argv);
		if (cmd_line->need_version())
		{
			return EXIT_SUCCESS;
		}
		if (cmd_line->need_help())
		{
			fmt::println("{}", cmd_line->help());
			return EXIT_SUCCESS;
		}
	}
	catch (const std::exception& e)
	{
		fmt::println(stderr, "Parse arguments failed: {}", e.what());
		return EXIT_FAILURE;
	}

	return core::Service().run(*cmd_line);
}
