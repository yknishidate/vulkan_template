
cmake_minimum_required(VERSION 3.16)

project(vulkan_framework)

file(GLOB FRAMEWORK_FILES "Vulkan-Samples/framework/*")
file(GLOB_RECURSE COMMON_FILES "Vulkan-Samples/framework/common/*")
file(GLOB_RECURSE GEOMETRY_FILES "Vulkan-Samples/framework/geometry/*")
file(GLOB_RECURSE RENDERING_FILES "Vulkan-Samples/framework/rendering/*")
file(GLOB_RECURSE SCENE_GRAPH_FILES "Vulkan-Samples/framework/scene_graph/*")
file(GLOB_RECURSE STATS_FILES "Vulkan-Samples/framework/stats/*")
file(GLOB_RECURSE CORE_FILES "Vulkan-Samples/framework/core/*")
file(GLOB_RECURSE GRAPHING_FILES "Vulkan-Samples/framework/graphing/*")

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

set(ENTRY_POINT_FILES
    # Header Files
    vulkan_framework.hpp
    # Source Files
    vulkan_framework.cpp)

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
source_group("scene_graph\\" FILES ${SCENE_GRAPH_FILES})
source_group("stats\\" FILES ${STATS_FILES})
source_group("graphing\\" FILES ${GRAPHING_FILES})
source_group("framework\\" FILES ${ENTRY_POINT_FILES})

set(PROJECT_FILES
    ${PLATFORM_FILES}
    ${PARSER_FILES}
    ${COMMON_FILES}
    ${FRAMEWORK_FILES}
    ${CORE_FILES}
    ${GEOMETRY_FILES}
    ${RENDERING_FILES}
    ${SCENE_GRAPH_FILES}
    ${STATS_FILES}
    ${GRAPHING_FILES}
    ${ENTRY_POINT_FILES})

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
    ${CMAKE_CURRENT_SOURCE_DIR}/Vulkan-Samples/app/plugins)

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

add_subdirectory(app)
