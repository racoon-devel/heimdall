#ifndef CONFIG_DEBUG_HPP_
#define CONFIG_DEBUG_HPP_

#include <spdlog/common.h>

namespace config
{

class Debug
{
public:
	using log_level_enum = spdlog::level::level_enum;

	log_level_enum log_level() const noexcept { return m_log_level; }
    
	void set_log_level(log_level_enum level) noexcept { m_log_level = level; }

private:
	log_level_enum m_log_level{spdlog::level::info};
};

} // namespace config

#endif // CONFIG_DEBUG_HPP_