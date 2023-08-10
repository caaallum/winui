cmake_minimum_required(VERSION 3.16)

project(ExampleLabel)

add_executable(${PROJECT_NAME} WIN32 main.cxx)

target_link_libraries(${PROJECT_NAME} PRIVATE winui)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
