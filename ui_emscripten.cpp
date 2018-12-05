#include <iostream>
#include <memory>
#include "imgui.h"
#include "imgui_impl_emscripten.h"

void Application_Frame();
void Application_Initialize();
void Application_Finalize();
std::unique_ptr<emscripten::SystemIntegration> integration;
std::unique_ptr<emscripten::Renderer> render_it;
int main()
{
    std::cout << "main" << std::endl;
    integration = std::make_unique<emscripten::SystemIntegration>();
    std::cout << "Gui created callbacks registered " << std::endl;
    std::cout << "creating renderer" << std::endl;
    integration->renderer = render_it.get();
    render_it = std::make_unique<emscripten::Renderer>(300);
    std::cout << "setting up renderer" << std::endl;

    render_it->setup_renderer();
    std::cout << "main done." << std::endl;

    Application_Initialize();
    integration->create_ui = [show_demo_window = true, show_another_window = false,
                              clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f)]() mutable {
        ImGui::StyleColorsDark();
        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about
        // Dear ImGui!).
        if (show_demo_window) ImGui::ShowDemoWindow(&show_demo_window);

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!");  // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");           // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &show_demo_window);  // Edit bools storing our window open/close state
            ImGui::Checkbox("Another Window", &show_another_window);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);             // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float*)&clear_color);  // Edit 3 floats representing a color

            if (ImGui::Button("Button"))  // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }

        // 3. Show another simple window.
        if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window);  // Pass a pointer to our bool variable (the window will have a closing
                                                                   // button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me")) show_another_window = false;
            ImGui::End();
        }
        Application_Frame();
    };
}
