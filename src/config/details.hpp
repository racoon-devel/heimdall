#ifndef CONFIG_DETAILS_HPP_
#define CONFIG_DETAILS_HPP_

#define RAPIDJSON_ASSERT(x) \
	if (!(x))               \
	throw std::runtime_error("json parsing error")

#include <rapidjson/rapidjson.h>
#include <rapidjson/writer.h>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/error/en.h>
#include <rapidjson/pointer.h>
#include <rapidjson/schema.h>
#include <rapidjson/stringbuffer.h>


namespace config
{
namespace details
{

template< class T >
T load_from_json(const rapidjson::Document::Object& obj);

}
} // namespace config

#endif // CONFIG_DETAILS_HPP_