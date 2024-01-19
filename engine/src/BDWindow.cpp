#include <BDWindow.hpp>
#include <stdexcept>

namespace bd{
    BDWindow::BDWindow(int w, int h, string name): width(w), height(h), winName(name){
        initWindow();
    }

    BDWindow::~BDWindow(){
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void BDWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface)
    {
        if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
        {
            throw runtime_error("failed to create window surface!");
        }
    }

    void BDWindow::initWindow()
    {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        window = glfwCreateWindow(width, height, winName.c_str(), nullptr, nullptr);
        glfwSetWindowUserPointer(window, this);
        glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
    }
    void BDWindow::framebufferResizeCallback(GLFWwindow *window, int width, int height)
    {
        auto bdWindow = reinterpret_cast<BDWindow *>(glfwGetWindowUserPointer(window));
        bdWindow->framebufferResized = true;
        bdWindow->width = width;
        bdWindow->height = height;
    }
}