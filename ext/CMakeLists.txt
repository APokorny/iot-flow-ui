
add_library(ImGui
    imgui/imgui.h
    imgui/imgui_internal.h
    imgui/imstb_rectpack.h
    imgui/imstb_textedit.h
    imgui/imstb_truetype.h
    imgui/imgui.cpp
    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_widgets.cpp
    )
target_include_directories(ImGui PUBLIC imgui/)
## if SDL and GL3 found ...
add_library(ImGui_sdl_gl3
    imgui/examples/imgui_impl_sdl.h
    imgui/examples/imgui_impl_opengl3.h
    imgui/examples/imgui_impl_sdl.cpp
    imgui/examples/imgui_impl_opengl3.cpp
    )
target_compile_definitions(ImGui_sdl_gl3 PUBLIC IMGUI_IMPL_OPENGL_LOADER_GLEW=1)
target_include_directories(ImGui_sdl_gl3 PUBLIC imgui/ imgui/examples ${SDL_INCLUDE_DIRS} ${GLEW_CLFAGS})
target_link_libraries(ImGui_sdl_gl3 PUBLIC ${GLEW_LDFAGS} ${GLEW_LIBRARIES})

add_library(ImGui_sdl_vulkan
    imgui/examples/imgui_impl_sdl.h
    imgui/examples/imgui_impl_vulkan.h
    imgui/examples/imgui_impl_sdl.cpp
    imgui/examples/imgui_impl_vulkan.cpp
    )
target_include_directories(ImGui_sdl_vulkan PUBLIC imgui/ imgui/examples ${SDL_INCLUDE_DIRS})
target_link_libraries(ImGui_sdl_vulkan PUBLIC ${VULKAN_LIBRARIES} ${SDL_LIBRARIES})

add_library(ImGui_cpp 
    imgui/misc/cpp/imgui_stdlib.h
    imgui/misc/cpp/imgui_stdlib.cpp
    )
target_include_directories(ImGui_cpp PUBLIC imgui/ imgui/misc/cpp/)

add_executable(binary_to_compressed_c
    imgui/misc/fonts/binary_to_compressed_c.cpp
    )
#if have FT2
add_library(ImGui_freetype
    imgui/misc/freetype/imgui_freetype.cpp
    )
target_include_directories(ImGui_freetype PUBLIC ${FT_INCLUDEDIR})
target_compile_options(ImGui_freetype PUBLIC ${FT_CFLAGS})
target_link_libraries(ImGui_freetype ImGui ${FT_LIBRARY})
add_subdirectory(picojson)
add_subdirectory(NodeEditor)
