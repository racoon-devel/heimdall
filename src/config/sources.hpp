#ifndef CONFIG_SOURCE_PROVIDER_HPP_
#define CONFIG_SOURCE_PROVIDER_HPP_

namespace config
{

enum class Provider
{
	kConfig = 0,
	kDatabase,
};

class Sources final
{
public:
	Provider provider() const noexcept { return m_provider; }

	void set_provider(Provider provider) noexcept { m_provider = provider; }

private:
	Provider m_provider{};
};

} // namespace config

#endif // CONFIG_SOURCE_PROVIDER_HPP_