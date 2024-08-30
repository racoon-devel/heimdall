#include "config.hpp"

#include <fstream>

#include <spdlog/spdlog.h>

#include "debug.hpp"
#include "details.hpp"

using namespace rapidjson;

namespace
{
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