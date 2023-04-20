//#include <api_vulkan_sample.h>
//#include <spdlog/spdlog.h>
//
//int main()
//{
//    spdlog::info("OK!");
//}


#include "common/logging.h"
#include "platform/platform.h"
#include "plugins/plugins.h"

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
#	include "platform/android/android_platform.h"
void android_main(android_app* state)
{
    vkb::AndroidPlatform platform{ state };
#elif defined(VK_USE_PLATFORM_WIN32_KHR)
#	include "platform/windows/windows_platform.h"
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                     PSTR lpCmdLine, INT nCmdShow)
{
    vkb::WindowsPlatform platform{ hInstance, hPrevInstance,
                                  lpCmdLine, nCmdShow };
#elif defined(VK_USE_PLATFORM_DISPLAY_KHR)
#	include "platform/unix/unix_d2d_platform.h"
int main(int argc, char* argv[])
{
    vkb::UnixD2DPlatform platform{ argc, argv };
#else
#	include "platform/unix/unix_platform.h"
int main(int argc, char* argv[])
{
#	if defined(VK_USE_PLATFORM_METAL_EXT)
    vkb::UnixPlatform platform{ vkb::UnixType::Mac, argc, argv };
#	elif defined(VK_USE_PLATFORM_XCB_KHR) || defined(VK_USE_PLATFORM_XLIB_KHR) || defined(VK_USE_PLATFORM_WAYLAND_KHR)
    vkb::UnixPlatform platform{ vkb::UnixType::Linux, argc, argv };
#	endif
#endif

    //auto code = platform.initialize(plugins::get_all());

    //if (code == vkb::ExitCode::Success)
    //{
    //    code = platform.main_loop();
    //}

    //platform.terminate(code);

#ifndef VK_USE_PLATFORM_ANDROID_KHR
    return EXIT_SUCCESS;
#endif
}

