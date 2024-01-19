#include <app.hpp>

App::App()
{
    window = new BDWindow(640, 480, "BDEngine");
    device = new BDDevice(window);
}