@echo off
cd Vulkan-Samples
cmake . -Bbuild/windows
cmake --build build/windows --config Release --target vulkan_samples
