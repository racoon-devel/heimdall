#ifndef SOURCE_FACTORY_HPP_
#define SOURCE_FACTORY_HPP_

#include <memory>

#include <config/sources.hpp>

#include "provider.hpp"

namespace source
{

class ProviderFactory
{
public:
	ProviderFactory() = delete;
    static std::unique_ptr<IProvider> create_provider(const config::Sources& conf);
};

} // namespace source

#endif // SOURCE_FACTORY_HPP_