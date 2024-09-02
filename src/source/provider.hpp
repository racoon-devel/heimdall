#ifndef SOURCE_PROVIDER_HPP_
#define SOURCE_PROVIDER_HPP_

#include <memory>
#include <vector>

#include "source.hpp"

namespace source
{

using List = std::vector< Source >;

/**
    @interface ISourcesController is a mediator interface for updating sources list
 */
class ISourcesController
{
public:
	virtual void update_source_list(List&& sources) noexcept = 0;
    virtual ~ISourcesController() = default;
};

/**
    @interface IProvider is an interface for classes, which provide changes of source list
 */
class IProvider
{
public:
	virtual void start(const std::shared_ptr<ISourcesController>& sources_controller) = 0;
	virtual void stop() = 0;
    virtual ~IProvider() = default;
};

} // namespace source

#endif // SOURCE_PROVIDER_HPP_