# Bluedragon
![logo](./docs/logo.png)

Is a Vulkan-powered, C++-made game engine.

## Build instructions

To configure the project, I added two custom options (see the [main CMake file](./CMakeLists.txt) and the [test CMake file](./test/CMakeLists.txt) and the [docs CMake file](./docs/CMakeLists.txt)):
- One for the test build (```BUILD_TEST```)
- and one for the documents (```BD_BUILD_DOCS```)

### How to build

> ***NOTE***: Typically, the Windows build engine is ***Visual Studio***, and for Unix ***Make***, but I will give general instructions

1. Check you have installed CMake and a proper generator
1. Run these commands
```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
#Or replace it with build system secified command
```

### How to run

If you activated ```BUILD_TEST```, just go to ./build/test/bd_test and run the executable.

If you activated ```BD_BUILD_DOCS```, go to ./build/docs/html/index.html and open it with your browser.
