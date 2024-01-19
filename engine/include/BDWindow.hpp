#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>
using namespace std;
namespace bd
{
    class BDWindow{
        public:
            BDWindow(int w, int h, string name);
           
            ~BDWindow();
            
            BDWindow(const BDWindow&) = delete;
            
            BDWindow& operator=(const BDWindow&) = delete;
            BDWindow(BDWindow&&) = delete;  
            bool shouldClose() { return glfwWindowShouldClose(window); }
            VkExtent2D getExtent() { return {static_cast<uint32_t>(width), static_cast<uint32_t>(height)}; }
            bool wasWindowResized() { return framebufferResized; }
            void resetWindowResizedFlag() { framebufferResized = false; }
            GLFWwindow *getGLFWwindow() const { return window; }

            void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

        private:
            GLFWwindow* window;
            bool framebufferResized = false;

            void initWindow();
            string winName;
            int width;
            int height;

            static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
    };
} // namespace bd
