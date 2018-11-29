#include "imgui_impl_emscripten.h"
#include <iostream>

int main(){
    std::cout << "main"<<std::endl;
    emscripten::Renderer render_it(120);

    render_it.setup_renderer();
    emscripten::SystemIntegration integration;
    std::cout << "main done."<<std::endl;
}
