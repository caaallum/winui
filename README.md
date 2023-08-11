[![Windows](https://github.com/caaallum/winui/actions/workflows/build.yml/badge.svg)](https://github.com/caaallum/winui/actions/workflows/build.yml)
# winui

Simple component style ui library for win32 applications

## Usage
### CMake
```cmake 
include(FetchContent)
FetchContent_Declare(winui
    GIT_REPOSITORY      https://github.com/caaallum/winui.git
    GIT_SHALLOW         TRUE
)
FetchContent_MakeAvailable(winui)

target_link_libraries(${PROJECT_NAME} PRIVATE winui)
```