project(CactusUI CXX)
cmake_minimum_required(VERSION 3.10)

message(STATUS "We are on " ${CMAKE_SYSTEM})

if(CMAKE_SYSTEM STREQUAL "Emscripten")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    set(VULKAN_ENABLED OFF)
else()
    set(VULKAN_ENABLED ON)
endif()


find_package( PkgConfig )
add_subdirectory(ext)

pkg_check_modules(VULKAN vulkan)
pkg_check_modules(SDL sdl2)
pkg_check_modules(GLEW glew)
pkg_check_modules(FT freetype2)

if(VULKAN_ENABLED)
    add_executable(ui_vk ui_vulkan.cpp Blueprints.cpp)
    target_link_libraries(ui_vk ImGui ImGui_sdl_vulkan NodeEditor Shared ${SDL_LIBRARIES} ${VULKAN_LIBRARIES})
endif()

add_executable(ui_gl ui_gles2.cpp Blueprints.cpp)
target_link_libraries(ui_gl ImGui ImGui_sdl_gl3 NodeEditor Shared ${SDL_LIBRARIES})
add_executable(ui ui.cpp)
