#include "vulkan_framework.hpp"
#include "hpp_api_vulkan_sample.h"

class App : public HPPApiVulkanSample {
public:
    App() = default;

    virtual ~App() override {}

    void update(float delta_time) override
    {
        LOGI("update: {}", delta_time)
    }

    void render(float delta_time) override
    {
        LOGI("render: {}", delta_time)
    }

    virtual void build_command_buffers() override {}

};

// Pass the custom class to framework
std::unique_ptr<vkb::Application> createApp() {
    return std::make_unique<App>();
}
