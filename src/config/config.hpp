#ifndef CONFIG_CONFIG_HPP_
#define CONFIG_CONFIG_HPP_
#include <string>
#include "debug.hpp"

namespace config
{

class Config
{
public:
    static Config load(const std::string& config_path);
    
	Debug debug() const { return m_debug; }

private:
	Debug m_debug{};
};

} // namespace config

#endif // CONFIG_CONFIG_HPP_