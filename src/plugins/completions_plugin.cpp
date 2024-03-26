#include "plugin_base.hpp"

#include "xplugin/xfactory.hpp"

class XPLUGIN_API CompletionsPlugin : public PluginBase
{
    public: 
        CompletionsPlugin() = default;
        virtual ~CompletionsPlugin() = default;

        void load() const override
        {
            // load the plugin
        }

    private:
        int m_some_data;
};

class XPLUGIN_API CompletionsPluginFactory : public PluginFactoryBase
{
    public:
        using factory_base_type = PluginFactoryBase;

        std::unique_ptr<PluginBase> create() override
        {
            return std::make_unique<CompletionsPlugin>();
        }
    
        std::string name() const override
        {
            return "CompletionsPlugin";
        }
        std::string description() const override
        {
            return "This is the completions plugin.";
        }

        std::string version() const override
        {
            return "0.10";
        }
};

XPLUGIN_CREATE_XPLUGIN_FACTORY(CompletionsPluginFactory)