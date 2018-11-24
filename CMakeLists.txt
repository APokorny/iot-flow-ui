project(CactusUI CXX)
cmake_minimum_required(VERSION 3.10)


find_package( PkgConfig )
add_subdirectory(ext)

pkg_check_modules(VULKAN vulkan)
pkg_check_modules(SDL sdl2)
pkg_check_modules(GLEW glew)
pkg_check_modules(FT freetype2)

add_executable(ui_vk ui_vulkan.cpp)
target_link_libraries(ui_vk ImGui ImGui_sdl_vulkan ${SDL_LIBRARIES} ${VULKAN_LIBRARIES})
add_executable(ui_gl ui_gles2.cpp)
target_link_libraries(ui_gl ImGui ImGui_sdl_gl3 ${SDL_LIBRARIES})
add_executable(ui ui.cpp)
