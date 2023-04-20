/* Copyright (c) 2019-2021, Arm Limited and Contributors
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 the "License";
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "vulkan_framework.hpp"

class MyApp : public vkb::Application {
    bool prepare(vkb::Platform& platform) override {
        if (!Application::prepare(platform)) {
            return false;
        }

        LOGI("Initializing Vulkan sample");
    }
};

std::unique_ptr<vkb::Application> createApp() {
    return std::make_unique<MyApp>();
}
