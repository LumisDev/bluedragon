#include "BDWindow.hpp"
using namespace std;
namespace bd{
    BDWindow::BDWindow(int w, int h, string name) : width(w), height(h), windowName(name){
        initWindow();
    }

    BDWindow::~BDWindow(){
        glfwDestroyWindow(window);
        glfwTerminate();
    }
}