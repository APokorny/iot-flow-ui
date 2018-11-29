
add_library(emsi STATIC imgui_impl_emscripten.cpp)
target_include_directories(emsi INTERFACE ${CMAKE_CURRENT_LIST_DIR} ${GL_INCLUDE_DIRS})
target_link_libraries(emsi EGL GL)
