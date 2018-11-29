#include "imgui_impl_emscripten.h"
#include <iostream>

int main(){
    std::cout << "main"<<std::endl;
    ems_init();
    std::cout << "main done."<<std::endl;
}
