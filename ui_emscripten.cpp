#include "imgui_impl_emscripten.h"
#include <iostream>

int main(){
    std::cout << "main"<<std::endl;
    emscripten::SystemIntegration integration;
    std::cout << "Gui created callbacks registered "<<std::endl;
    std::cout << "creating renderer"<<std::endl;
    emscripten::Renderer render_it(120);
    std::cout << "setting up renderer"<<std::endl;

    render_it.setup_renderer();
    std::cout << "main done."<<std::endl;
}
