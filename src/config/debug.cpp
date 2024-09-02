#include "debug.hpp"

#include <exception>

#include <spdlog/common-inl.h>
#include <spdlog/common.h>
#include <spdlog/spdlog.h>
#include <stdexcept>

#include "details.hpp"

namespace config
{
namespace details
{
template<>
Debug load_from_json< Debug >(
	[[maybe_unused]] const rapidjson::Document::Object& obj)
{
	Debug result;
	result.set_log_level(spdlog::level::from_str(obj["log_level"].GetString()));
	return result;
}
} // namespace details
} // namespace config