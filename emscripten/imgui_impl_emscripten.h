#pragma once
#include <GLES3/gl3.h>
#include <functional>
#include <string>

struct ImDrawData;

namespace emscripten
{
struct Renderer
{
   public:
    explicit Renderer(int glsl_version);
    void setup_renderer();
    void render_imgui_data(ImDrawData& draw_data);
    void finish_frame();
    ~Renderer();

   private:
    void create_programs();
    void create_font_texture();
    void cleanup_font_texture();
    void cleanup_programs();
    int glsl_version{300};
    std::string glsl_version_text{"#version 300 es\n"};
    GLuint font_texture{0};
    GLuint shader_handle;
    GLuint vert_handle;
    GLuint frag_handle;
    unsigned int vbo_handle{0};
    unsigned int element_handle{0};
    int texture_loc;
    int proj_matrix_loc;
    int position_loc;
    int uv_loc;
    int color_loc;
};

struct SystemIntegration
{
    Renderer* renderer;
    int width, height;
    int mouse_status[8];
    std::function<void()> create_ui;
    SystemIntegration();
    void loop();

   private:
    void update_imgui_state();
    void cleanup_imgui_state();
    void reset_mouse_state();
};

}  // namespace emscripten
