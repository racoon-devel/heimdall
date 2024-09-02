#include "config.hpp"

#include "details.hpp"

#include <fstream>
#include <stdexcept>

#include <fmt/core.h>
#include <rapidjson/document.h>
#include <rapidjson/schema.h>
#include <spdlog/spdlog.h>

#include "debug.hpp"

using namespace rapidjson;

extern char _binary_config_schema_json_start;
extern char _binary_config_schema_json_end;

namespace
{

const auto config_schema_size =
	&_binary_config_schema_json_end - &_binary_config_schema_json_start;

auto load_config_schema()
{
	Document config;
	if (config
			.Parse(&_binary_config_schema_json_start,
				   static_cast< size_t >(config_schema_size))
			.HasParseError())
	{
		throw std::runtime_error(
			fmt::format("parse configuration schema failed: {}",
						GetParseError_En(config.GetParseError())));
	}
	return SchemaDocument(config);
}

void validate(const Document& doc, const SchemaDocument& schema)
{
	SchemaValidator validator(schema);
	if (!doc.Accept(validator))
	{
		StringBuffer error;

		validator.GetInvalidSchemaPointer().Stringify(error);
		auto error_msg =
			fmt::format("validation failed: path='{}' ", error.GetString());
		error.Clear();

		validator.GetInvalidDocumentPointer().Stringify(error);
		error_msg =
			fmt::format("{} param='{}', keyword='{}'", error_msg,
						error.GetString(), validator.GetInvalidSchemaKeyword());

		throw std::runtime_error(error_msg);
	}
}

Document parse_config_file(const std::string& config_path)
{
	std::ifstream input_file(config_path);
	if (!input_file.is_open())
	{
		throw std::runtime_error(fmt::format(
			"open '{}' failed: {}", config_path, std::strerror(errno)));
	}

	IStreamWrapper isw(input_file);
	Document       doc;
	if (doc.ParseStream(isw).HasParseError())
	{
		throw std::runtime_error(fmt::format(
			"parse config failed: {}", GetParseError_En(doc.GetParseError())));
	}

	auto schema = load_config_schema();
	validate(doc, schema);
	return doc;
}

std::string document_to_string(const Document& doc)
{
	StringBuffer           str_buf;
	Writer< StringBuffer > writer(str_buf);
	doc.Accept(writer);
	return str_buf.GetString();
}

} // namespace

namespace config
{
Config Config::load(const std::string& config_path)
{
	auto doc = parse_config_file(config_path);
	SPDLOG_INFO("Configuration: {}", document_to_string(doc));

	auto obj   = doc.GetObject();
	auto debug = details::load_from_json< Debug >(obj["debug"].GetObject());

	Config result;
	result.m_debug = debug;
	return result;
}

} // namespace config