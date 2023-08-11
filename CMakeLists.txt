cmake_minimum_required(VERSION 3.16)

set(VERSION 0.1.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(winui)

option(WINUI_EXAMPLES "Build winui examples" OFF)

file(GLOB 
    SRC
    src/window.cxx
    src/component.cxx
    src/button.cxx
    src/label.cxx
    src/textfield.cxx
    src/combobox.cxx
    src/checkbox.cxx

    src/dllmain.cxx
)

file(GLOB
    PUBLIC_HEADERS
    include/winui.h
)

file(GLOB
    PRIVATE_HEADERS
    include/winui/stdafx.h
    include/winui/targetver.h
    
    include/winui/components/window.h
    include/winui/components/component.h
    include/winui/components/button.h
    include/winui/components/label.h
    include/winui/components/textfield.h
    include/winui/components/combobox.h
    include/winui/components/checkbox.h
    
    include/winui/util/vector2.h
)

add_library(${PROJECT_NAME} STATIC ${SRC} ${PRIVATE_HEADERS} ${PUBLIC_HEADERS})

target_include_directories(${PROJECT_NAME} 
    PRIVATE 
        include
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    winui.cmake
    VERSION ${VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(FILES ${PUBLIC_HEADERS} DESTINATION "include/")
install(FILES ${PRIVATE_HEADERS} DESTINATION "include/winui")
install(TARGETS ${PROJECT_NAME} 
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

if (WINUI_EXAMPLES)
  add_subdirectory(examples)
endif()

macro(msvc_group curdir)
  file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${curdir} ${PROJECT_SOURCE_DIR}/${curdir}/*)

  foreach(child ${children})
    if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${curdir}/${child})
      msvc_group(${curdir}/${child})
    else()
      string(REPLACE "/" "\\" groupname ${curdir})
      source_group(${groupname} FILES ${PROJECT_SOURCE_DIR}/${curdir}/${child})
    endif()
  endforeach()
endmacro()

msvc_group(src)
msvc_group(include)