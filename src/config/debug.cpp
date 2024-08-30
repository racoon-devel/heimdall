#include "debug.hpp"

#include "details.hpp"

namespace config
{
namespace details
{
template<> Debug load_from_json< Debug >([[maybe_unused]]const rapidjson::Document::Object& obj)
{
	return {};
}
} // namespace details
} // namespace config