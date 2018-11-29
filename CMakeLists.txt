project(CactusUI CXX)
cmake_minimum_required(VERSION 3.10)
SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake/Modules/ ${CMAKE_MODULE_PATH})

if(EMSCRIPTEN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    set(VULKAN_ENABLED OFF)
    set(GL3_ENABLED OFF)
    set(GL2_ENABLED OFF)
    set(GL_INCLUDE_DIRS ${EMSCRIPTEN_SYSTEM}/include/GL)
    set(EMSCRIPRTEN_INCLUDE_DIRS ${EMSCRIPTEN_SYSTEM}/include/)
    set(GL_LIBRARIES GL)

    set(EMSCRIPTEN_ENABLED ON)
else()
    find_package( PkgConfig )

    pkg_check_modules(GL gl)
    pkg_check_modules(SDL sdl2)
    pkg_check_modules(GLEW glew)
    pkg_check_modules(FT freetype2)
    pkg_check_modules(VULKAN vulkan)

    set(VULKAN_ENABLED ${VULKAN_FOUND})
    set(GL3_ENABLED ${GL_FOUND})
    set(GL2_ENABLED ${GL_FOUND})
endif()

add_subdirectory(ext)
add_subdirectory(emscripten)


if(VULKAN_ENABLED)
    add_executable(ui_vk ui_vulkan.cpp Blueprints.cpp)
    target_link_libraries(ui_vk ImGui ImGui_sdl_vulkan NodeEditor Shared ${SDL_LIBRARIES} ${VULKAN_LIBRARIES})
endif()

if(GL3_ENABLED)
    add_executable(ui_gl ui_gl3.cpp Blueprints.cpp)
    target_link_libraries(ui_gl ImGui ImGui_sdl_gl3 NodeEditor Shared ${SDL_LIBRARIES})
endif()

if(GL2_ENABLED)
    add_executable(ui_gl2 ui_gl2.cpp Blueprints.cpp)
    target_link_libraries(ui_gl2 ImGui ImGui_sdl_gl2 NodeEditor Shared ${SDL_LIBRARIES})
endif()

if(EMSCRIPTEN_ENABLED)
    add_executable(ui_emscripten ui_emscripten.cpp)
    target_link_libraries(ui_emscripten emsi EGL GL)
    #target_link_libraries(ui_emscripten ImGui NodeEditor Shared)
endif()
add_executable(ui ui.cpp)
