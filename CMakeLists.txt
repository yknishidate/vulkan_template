
cmake_minimum_required(VERSION 3.16)

project(vulkan_framework)

# Framework
set(FRAMEWORK_FILES
    # Header Files
    Vulkan-Samples/framework/gui.h
    Vulkan-Samples/framework/glsl_compiler.h
    Vulkan-Samples/framework/spirv_reflection.h
    Vulkan-Samples/framework/gltf_loader.h
    Vulkan-Samples/framework/buffer_pool.h
    Vulkan-Samples/framework/debug_info.h
    Vulkan-Samples/framework/fence_pool.h
    Vulkan-Samples/framework/heightmap.h
    Vulkan-Samples/framework/semaphore_pool.h
    Vulkan-Samples/framework/resource_binding_state.h
    Vulkan-Samples/framework/resource_cache.h
    Vulkan-Samples/framework/resource_record.h
    Vulkan-Samples/framework/resource_replay.h
    Vulkan-Samples/framework/vulkan_sample.h
    Vulkan-Samples/framework/api_vulkan_sample.h
    Vulkan-Samples/framework/timer.h
    Vulkan-Samples/framework/camera.h
    Vulkan-Samples/framework/hpp_api_vulkan_sample.h
    Vulkan-Samples/framework/hpp_buffer_pool.h
    Vulkan-Samples/framework/hpp_fence_pool.h
    Vulkan-Samples/framework/hpp_glsl_compiler.h
    Vulkan-Samples/framework/hpp_gltf_loader.h
    Vulkan-Samples/framework/hpp_gui.h
    Vulkan-Samples/framework/hpp_resource_binding_state.h
    Vulkan-Samples/framework/hpp_resource_cache.h
    Vulkan-Samples/framework/hpp_vulkan_sample.h
    # Source Files
    Vulkan-Samples/framework/gui.cpp
    Vulkan-Samples/framework/glsl_compiler.cpp
    Vulkan-Samples/framework/spirv_reflection.cpp
    Vulkan-Samples/framework/gltf_loader.cpp
    Vulkan-Samples/framework/debug_info.cpp
    Vulkan-Samples/framework/buffer_pool.cpp
    Vulkan-Samples/framework/fence_pool.cpp
    Vulkan-Samples/framework/heightmap.cpp
    Vulkan-Samples/framework/semaphore_pool.cpp
    Vulkan-Samples/framework/resource_binding_state.cpp
    Vulkan-Samples/framework/resource_cache.cpp
    Vulkan-Samples/framework/resource_record.cpp
    Vulkan-Samples/framework/resource_replay.cpp
    Vulkan-Samples/framework/vulkan_sample.cpp
    Vulkan-Samples/framework/api_vulkan_sample.cpp
    Vulkan-Samples/framework/timer.cpp
    Vulkan-Samples/framework/camera.cpp
    Vulkan-Samples/framework/hpp_gui.cpp
    Vulkan-Samples/framework/hpp_api_vulkan_sample.cpp
	Vulkan-Samples/framework/hpp_vulkan_sample.cpp)

set(COMMON_FILES
    # Header Files
    Vulkan-Samples/framework/common/vk_common.h
    Vulkan-Samples/framework/common/vk_initializers.h
    Vulkan-Samples/framework/common/glm_common.h 
    Vulkan-Samples/framework/common/resource_caching.h
    Vulkan-Samples/framework/common/logging.h
    Vulkan-Samples/framework/common/helpers.h
    Vulkan-Samples/framework/common/error.h
    Vulkan-Samples/framework/common/utils.h
    Vulkan-Samples/framework/common/strings.h
    Vulkan-Samples/framework/common/tags.h
    Vulkan-Samples/framework/common/hpp_error.h
    Vulkan-Samples/framework/common/hpp_strings.h
    Vulkan-Samples/framework/common/hpp_utils.h
    Vulkan-Samples/framework/common/hpp_vk_common.h
    # Source Files
    Vulkan-Samples/framework/common/error.cpp
    Vulkan-Samples/framework/common/vk_common.cpp
    Vulkan-Samples/framework/common/utils.cpp
    Vulkan-Samples/framework/common/strings.cpp)

set(GEOMETRY_FILES
    # Header Files
    Vulkan-Samples/framework/geometry/frustum.h
    # Source Files
    Vulkan-Samples/framework/geometry/frustum.cpp)

set(RENDERING_FILES
    # Header files
    Vulkan-Samples/framework/rendering/pipeline_state.h
    Vulkan-Samples/framework/rendering/postprocessing_pipeline.h
    Vulkan-Samples/framework/rendering/postprocessing_pass.h
    Vulkan-Samples/framework/rendering/postprocessing_renderpass.h
    Vulkan-Samples/framework/rendering/postprocessing_computepass.h
    Vulkan-Samples/framework/rendering/render_context.h
    Vulkan-Samples/framework/rendering/render_frame.h
    Vulkan-Samples/framework/rendering/render_pipeline.h
    Vulkan-Samples/framework/rendering/render_target.h
    Vulkan-Samples/framework/rendering/subpass.h
    Vulkan-Samples/framework/rendering/hpp_pipeline_state.h
    Vulkan-Samples/framework/rendering/hpp_render_context.h
    Vulkan-Samples/framework/rendering/hpp_render_frame.h
    Vulkan-Samples/framework/rendering/hpp_render_pipeline.h
    Vulkan-Samples/framework/rendering/hpp_render_target.h
    Vulkan-Samples/framework/rendering/hpp_subpass.h
    # Source files
    Vulkan-Samples/framework/rendering/pipeline_state.cpp
    Vulkan-Samples/framework/rendering/postprocessing_pipeline.cpp
    Vulkan-Samples/framework/rendering/postprocessing_pass.cpp
    Vulkan-Samples/framework/rendering/postprocessing_renderpass.cpp
    Vulkan-Samples/framework/rendering/postprocessing_computepass.cpp
    Vulkan-Samples/framework/rendering/render_context.cpp
    Vulkan-Samples/framework/rendering/render_frame.cpp
    Vulkan-Samples/framework/rendering/render_pipeline.cpp
    Vulkan-Samples/framework/rendering/render_target.cpp
    Vulkan-Samples/framework/rendering/subpass.cpp
    Vulkan-Samples/framework/rendering/hpp_render_context.cpp
    Vulkan-Samples/framework/rendering/hpp_render_target.cpp)

set(RENDERING_SUBPASSES_FILES
    # Header files
    Vulkan-Samples/framework/rendering/subpasses/forward_subpass.h
    Vulkan-Samples/framework/rendering/subpasses/lighting_subpass.h
    Vulkan-Samples/framework/rendering/subpasses/geometry_subpass.h
    Vulkan-Samples/framework/rendering/subpasses/hpp_forward_subpass.h
    # Source files
    Vulkan-Samples/framework/rendering/subpasses/forward_subpass.cpp
    Vulkan-Samples/framework/rendering/subpasses/lighting_subpass.cpp
    Vulkan-Samples/framework/rendering/subpasses/geometry_subpass.cpp)

set(SCENE_GRAPH_FILES
    # Header Files
    Vulkan-Samples/framework/scene_graph/component.h
    Vulkan-Samples/framework/scene_graph/node.h
    Vulkan-Samples/framework/scene_graph/scene.h
    Vulkan-Samples/framework/scene_graph/script.h
    # Source Files
    Vulkan-Samples/framework/scene_graph/component.cpp
    Vulkan-Samples/framework/scene_graph/node.cpp
    Vulkan-Samples/framework/scene_graph/scene.cpp
    Vulkan-Samples/framework/scene_graph/script.cpp)

set(SCENE_GRAPH_COMPONENT_FILES
    # Header Files
    Vulkan-Samples/framework/scene_graph/components/aabb.h
    Vulkan-Samples/framework/scene_graph/components/camera.h
    Vulkan-Samples/framework/scene_graph/components/perspective_camera.h
    Vulkan-Samples/framework/scene_graph/components/orthographic_camera.h
    Vulkan-Samples/framework/scene_graph/components/image.h
    Vulkan-Samples/framework/scene_graph/components/light.h
    Vulkan-Samples/framework/scene_graph/components/material.h
    Vulkan-Samples/framework/scene_graph/components/mesh.h
    Vulkan-Samples/framework/scene_graph/components/pbr_material.h
    Vulkan-Samples/framework/scene_graph/components/sampler.h
    Vulkan-Samples/framework/scene_graph/components/sub_mesh.h
    Vulkan-Samples/framework/scene_graph/components/texture.h
    Vulkan-Samples/framework/scene_graph/components/transform.h
    Vulkan-Samples/framework/scene_graph/components/image/astc.h
    Vulkan-Samples/framework/scene_graph/components/image/ktx.h
    Vulkan-Samples/framework/scene_graph/components/image/stb.h
    Vulkan-Samples/framework/scene_graph/components/hpp_image.h
    Vulkan-Samples/framework/scene_graph/components/hpp_sub_mesh.h
    # Source Files
    Vulkan-Samples/framework/scene_graph/components/aabb.cpp
    Vulkan-Samples/framework/scene_graph/components/camera.cpp
    Vulkan-Samples/framework/scene_graph/components/perspective_camera.cpp
    Vulkan-Samples/framework/scene_graph/components/orthographic_camera.cpp
    Vulkan-Samples/framework/scene_graph/components/image.cpp
    Vulkan-Samples/framework/scene_graph/components/light.cpp
    Vulkan-Samples/framework/scene_graph/components/material.cpp
    Vulkan-Samples/framework/scene_graph/components/mesh.cpp
    Vulkan-Samples/framework/scene_graph/components/pbr_material.cpp
    Vulkan-Samples/framework/scene_graph/components/sampler.cpp
    Vulkan-Samples/framework/scene_graph/components/sub_mesh.cpp
    Vulkan-Samples/framework/scene_graph/components/texture.cpp
    Vulkan-Samples/framework/scene_graph/components/transform.cpp
    Vulkan-Samples/framework/scene_graph/components/image/astc.cpp
    Vulkan-Samples/framework/scene_graph/components/image/ktx.cpp
    Vulkan-Samples/framework/scene_graph/components/image/stb.cpp)

set(SCENE_GRAPH_SCRIPTS_FILES
    # Header Files
    Vulkan-Samples/framework/scene_graph/scripts/free_camera.h
    Vulkan-Samples/framework/scene_graph/scripts/node_animation.h
    Vulkan-Samples/framework/scene_graph/scripts/animation.h
    # Source Files
    Vulkan-Samples/framework/scene_graph/scripts/free_camera.cpp
    Vulkan-Samples/framework/scene_graph/scripts/node_animation.cpp
    Vulkan-Samples/framework/scene_graph/scripts/animation.cpp)

set(STATS_FILES
    # Header Files
    Vulkan-Samples/framework/stats/stats.h
    Vulkan-Samples/framework/stats/stats_common.h
    Vulkan-Samples/framework/stats/stats_provider.h
    Vulkan-Samples/framework/stats/frame_time_stats_provider.h
    Vulkan-Samples/framework/stats/hwcpipe_stats_provider.h
    Vulkan-Samples/framework/stats/vulkan_stats_provider.h
    Vulkan-Samples/framework/stats/hpp_stats.h

    # Source Files
    Vulkan-Samples/framework/stats/stats.cpp
    Vulkan-Samples/framework/stats/stats_provider.cpp
    Vulkan-Samples/framework/stats/frame_time_stats_provider.cpp
    Vulkan-Samples/framework/stats/hwcpipe_stats_provider.cpp
    Vulkan-Samples/framework/stats/vulkan_stats_provider.cpp)

set(CORE_FILES
    # Header Files
    Vulkan-Samples/framework/core/instance.h
    Vulkan-Samples/framework/core/physical_device.h
    Vulkan-Samples/framework/core/device.h
    Vulkan-Samples/framework/core/debug.h
    Vulkan-Samples/framework/core/shader_module.h
    Vulkan-Samples/framework/core/pipeline_layout.h
    Vulkan-Samples/framework/core/pipeline.h
    Vulkan-Samples/framework/core/descriptor_set_layout.h
    Vulkan-Samples/framework/core/descriptor_pool.h
    Vulkan-Samples/framework/core/descriptor_set.h
    Vulkan-Samples/framework/core/queue.h
    Vulkan-Samples/framework/core/command_pool.h
    Vulkan-Samples/framework/core/swapchain.h
    Vulkan-Samples/framework/core/command_buffer.h
    Vulkan-Samples/framework/core/buffer.h
    Vulkan-Samples/framework/core/image.h
    Vulkan-Samples/framework/core/image_view.h
    Vulkan-Samples/framework/core/sampled_image.h
    Vulkan-Samples/framework/core/instance.h
    Vulkan-Samples/framework/core/sampler.h
    Vulkan-Samples/framework/core/framebuffer.h
    Vulkan-Samples/framework/core/render_pass.h
    Vulkan-Samples/framework/core/query_pool.h
    Vulkan-Samples/framework/core/scratch_buffer.h
    Vulkan-Samples/framework/core/acceleration_structure.h
    Vulkan-Samples/framework/core/shader_binding_table.h
    Vulkan-Samples/framework/core/hpp_buffer.h
    Vulkan-Samples/framework/core/hpp_command_buffer.h
    Vulkan-Samples/framework/core/hpp_command_pool.h
    Vulkan-Samples/framework/core/hpp_debug.h
    Vulkan-Samples/framework/core/hpp_descriptor_set_layout.h
    Vulkan-Samples/framework/core/hpp_device.h
    Vulkan-Samples/framework/core/hpp_framebuffer.h
    Vulkan-Samples/framework/core/hpp_image.h
    Vulkan-Samples/framework/core/hpp_image_view.h
    Vulkan-Samples/framework/core/hpp_instance.h
    Vulkan-Samples/framework/core/hpp_physical_device.h
    Vulkan-Samples/framework/core/hpp_pipeline.h
    Vulkan-Samples/framework/core/hpp_pipeline_layout.h
    Vulkan-Samples/framework/core/hpp_query_pool.h
    Vulkan-Samples/framework/core/hpp_queue.h
	Vulkan-Samples/framework/core/hpp_render_pass.h
    Vulkan-Samples/framework/core/hpp_sampler.h
    Vulkan-Samples/framework/core/hpp_shader_module.h
    Vulkan-Samples/framework/core/hpp_swapchain.h
    Vulkan-Samples/framework/core/hpp_vulkan_resource.h
    Vulkan-Samples/framework/core/vulkan_resource.h
    # Source Files
    Vulkan-Samples/framework/core/instance.cpp
    Vulkan-Samples/framework/core/physical_device.cpp
    Vulkan-Samples/framework/core/device.cpp
    Vulkan-Samples/framework/core/debug.cpp
    Vulkan-Samples/framework/core/image.cpp
    Vulkan-Samples/framework/core/shader_module.cpp
    Vulkan-Samples/framework/core/pipeline_layout.cpp
    Vulkan-Samples/framework/core/pipeline.cpp
    Vulkan-Samples/framework/core/descriptor_set_layout.cpp
    Vulkan-Samples/framework/core/descriptor_pool.cpp
    Vulkan-Samples/framework/core/descriptor_set.cpp
    Vulkan-Samples/framework/core/queue.cpp
    Vulkan-Samples/framework/core/command_pool.cpp
    Vulkan-Samples/framework/core/swapchain.cpp
    Vulkan-Samples/framework/core/command_buffer.cpp
    Vulkan-Samples/framework/core/buffer.cpp
    Vulkan-Samples/framework/core/image.cpp
    Vulkan-Samples/framework/core/image_view.cpp
    Vulkan-Samples/framework/core/sampled_image.cpp
    Vulkan-Samples/framework/core/instance.cpp
    Vulkan-Samples/framework/core/sampler.cpp
    Vulkan-Samples/framework/core/framebuffer.cpp
    Vulkan-Samples/framework/core/render_pass.cpp
    Vulkan-Samples/framework/core/query_pool.cpp
    Vulkan-Samples/framework/core/scratch_buffer.cpp
    Vulkan-Samples/framework/core/acceleration_structure.cpp
    Vulkan-Samples/framework/core/shader_binding_table.cpp
    Vulkan-Samples/framework/core/vulkan_resource.cpp
    Vulkan-Samples/framework/core/hpp_buffer.cpp
    Vulkan-Samples/framework/core/hpp_command_buffer.cpp
    Vulkan-Samples/framework/core/hpp_command_pool.cpp
    Vulkan-Samples/framework/core/hpp_device.cpp
    Vulkan-Samples/framework/core/hpp_image.cpp
    Vulkan-Samples/framework/core/hpp_image_view.cpp
    Vulkan-Samples/framework/core/hpp_instance.cpp
    Vulkan-Samples/framework/core/hpp_physical_device.cpp
    Vulkan-Samples/framework/core/hpp_queue.cpp
    Vulkan-Samples/framework/core/hpp_swapchain.cpp
    Vulkan-Samples/framework/core/hpp_vulkan_resource.cpp
)

set(PLATFORM_FILES
    # Header Files
    Vulkan-Samples/framework/platform/application.h
    Vulkan-Samples/framework/platform/platform.h
    Vulkan-Samples/framework/platform/window.h
    Vulkan-Samples/framework/platform/filesystem.h
    Vulkan-Samples/framework/platform/input_events.h
    Vulkan-Samples/framework/platform/configuration.h
    Vulkan-Samples/framework/platform/parser.h
    Vulkan-Samples/framework/platform/headless_window.h
    Vulkan-Samples/framework/platform/plugins/plugin.h
    Vulkan-Samples/framework/platform/plugins/plugin_base.h
    Vulkan-Samples/framework/platform/hpp_application.h
    Vulkan-Samples/framework/platform/hpp_platform.h
    Vulkan-Samples/framework/platform/hpp_window.h

    # Source Files
    Vulkan-Samples/framework/platform/headless_window.cpp
    Vulkan-Samples/framework/platform/application.cpp
    Vulkan-Samples/framework/platform/platform.cpp
    Vulkan-Samples/framework/platform/window.cpp
    Vulkan-Samples/framework/platform/filesystem.cpp
    Vulkan-Samples/framework/platform/input_events.cpp
    Vulkan-Samples/framework/platform/configuration.cpp
    Vulkan-Samples/framework/platform/parser.cpp
    Vulkan-Samples/framework/platform/plugins/plugin.cpp)

set(GLFW_FILES
    # Header Files
    Vulkan-Samples/framework/platform/glfw_window.h
    # Source Files
    Vulkan-Samples/framework/platform/glfw_window.cpp
)

set(PARSER_FILES
    # Header Files
    Vulkan-Samples/framework/platform/parsers/CLI11.h
    Vulkan-Samples/framework/platform/parsers/help_formatter.h
    # Source Files
    Vulkan-Samples/framework/platform/parsers/CLI11.cpp
    Vulkan-Samples/framework/platform/parsers/help_formatter.cpp
)

set(GRAPHING_FILES
    # Header Files
    Vulkan-Samples/framework/graphing/graph.h
    Vulkan-Samples/framework/graphing/graph_node.h
    Vulkan-Samples/framework/graphing/scene_graph.h
    Vulkan-Samples/framework/graphing/framework_graph.h

    # Source Files
    Vulkan-Samples/framework/graphing/graph.cpp
    Vulkan-Samples/framework/graphing/graph_node.cpp
    Vulkan-Samples/framework/graphing/scene_graph.cpp
    Vulkan-Samples/framework/graphing/framework_graph.cpp)

set(ANDROID_FILES
    # Header Files
    Vulkan-Samples/framework/platform/android/android_platform.h
    Vulkan-Samples/framework/platform/android/android_window.h
    # Source Files
    Vulkan-Samples/framework/platform/android/android_platform.cpp
    Vulkan-Samples/framework/platform/android/android_window.cpp)

set(WINDOWS_FILES
    # Header Files
    Vulkan-Samples/framework/platform/windows/windows_platform.h
    # Source Files
    Vulkan-Samples/framework/platform/windows/windows_platform.cpp)

set(UNIX_FILES
    # Header Files
    Vulkan-Samples/framework/platform/unix/unix_platform.h
    # Source Files
    Vulkan-Samples/framework/platform/unix/unix_platform.cpp)

set(LINUX_D2D_FILES
    # Header Files
    Vulkan-Samples/framework/platform/unix/unix_d2d_platform.h
    Vulkan-Samples/framework/platform/unix/direct_window.h
    # Source Files
    Vulkan-Samples/framework/platform/unix/unix_d2d_platform.cpp
    Vulkan-Samples/framework/platform/unix/direct_window.cpp) 

source_group("\\" FILES ${FRAMEWORK_FILES})
source_group("common\\" FILES ${COMMON_FILES})
source_group("platform\\" FILES ${PLATFORM_FILES})
source_group("platform\\" FILES ${GLFW_FILES})
source_group("platform\\parsers" FILES ${PARSER_FILES})
source_group("platform\\windows" FILES ${WINDOWS_FILES})
source_group("platform\\android" FILES ${ANDROID_FILES})
source_group("platform\\unix" FILES ${UNIX_FILES})
source_group("platform\\unix" FILES ${LINUX_D2D_FILES})
source_group("core\\" FILES ${CORE_FILES})
source_group("geometry\\" FILES ${GEOMETRY_FILES})
source_group("rendering\\" FILES ${RENDERING_FILES})
source_group("rendering\\subpasses" FILES ${RENDERING_SUBPASSES_FILES})
source_group("scene_graph\\" FILES ${SCENE_GRAPH_FILES})
source_group("scene_graph\\components\\" FILES ${SCENE_GRAPH_COMPONENT_FILES})
source_group("scene_graph\\scripts\\" FILES ${SCENE_GRAPH_SCRIPTS_FILES})
source_group("stats\\" FILES ${STATS_FILES})
source_group("graphing\\" FILES ${GRAPHING_FILES})

set(PROJECT_FILES
    vulkan_framework.hpp
    vulkan_framework.cpp
    ${PLATFORM_FILES}
    ${PARSER_FILES}
    ${COMMON_FILES}
    ${FRAMEWORK_FILES}
    ${CORE_FILES}
    ${GEOMETRY_FILES}
    ${RENDERING_FILES}
    ${RENDERING_SUBPASSES_FILES}
    ${SCENE_GRAPH_FILES}
    ${SCENE_GRAPH_COMPONENT_FILES}
    ${SCENE_GRAPH_SCRIPTS_FILES}
    ${STATS_FILES}
    ${GRAPHING_FILES})

# Add files based on platform
if(ANDROID)
    list(APPEND PROJECT_FILES ${ANDROID_FILES})
    message(STATUS "Android platform detected")
else()
    if(DIRECT_TO_DISPLAY)
        list(APPEND PROJECT_FILES ${LINUX_D2D_FILES})
        message(STATUS "Unix d2d platform detected")
    else()
        list(APPEND PROJECT_FILES ${GLFW_FILES})
        if(WIN32)
            list(APPEND PROJECT_FILES ${WINDOWS_FILES})
            message(STATUS "Windows platform detected")
        else()
            list(APPEND PROJECT_FILES ${UNIX_FILES})
            message(STATUS "Unix platform detected")
        endif()
    endif()
endif()

# Set the path to the Vulkan-Samples folder
set(VULKAN_SAMPLES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Vulkan-Samples")

# Include the Vulkan-Samples framework and external libraries
add_subdirectory("${VULKAN_SAMPLES_DIR}/third_party" third_party)

# Create an executable target for your project
add_library(${PROJECT_NAME} ${PROJECT_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Vulkan-Samples/framework
    ${CMAKE_CURRENT_SOURCE_DIR}/Vulkan-Samples/app/
    ${CMAKE_CURRENT_SOURCE_DIR}/Vulkan-Samples/app/apps
    ${CMAKE_CURRENT_SOURCE_DIR}/Vulkan-Samples/app/plugins
    )

# Link third party libraries
target_link_libraries(${PROJECT_NAME} PUBLIC
    volk
    ktx
    stb
    astc
    imgui
    tinygltf
    glm
    glslang
    SPIRV
    vma
    hwcpipe
    spirv-cross-glsl
    glslang-default-resource-limits
    spdlog
    ctpl
    CLI11::CLI11)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PUBLIC /MP)
endif()

# Link platform specific libraries
if(ANDROID)
    # Import game-activity static lib inside the game-activity_static prefab module.
    find_package(game-activity REQUIRED CONFIG)
    target_link_libraries(${PROJECT_NAME} PUBLIC log android game-activity::game-activity_static)
else()
    if (DIRECT_TO_DISPLAY)
        target_link_libraries(${PROJECT_NAME} PRIVATE dl)
    else()
        target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
    endif()
endif()

if(VKB_DO_CLANG_TIDY)
    set_target_properties(framework PROPERTIES CXX_CLANG_TIDY "${VKB_DO_CLANG_TIDY}")
endif()

target_compile_definitions(${PROJECT_NAME} PRIVATE
    "VULKAN_SAMPLES_DIRECTORY=\"${CMAKE_CURRENT_SOURCE_DIR}/Vulkan-Samples/\""
)

add_subdirectory(example)
