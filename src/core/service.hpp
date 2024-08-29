#ifndef CORE_SERVICE_HPP_
#define CORE_SERVICE_HPP_

#include <memory>

#include <spdlog/logger.h>

class Service final
{
public:
	int run(int argc, char** argv);

private:
	std::shared_ptr< spdlog::logger > m_logger{};

	void init_logging();
};

#endif // CORE_SERVICE_HPP_