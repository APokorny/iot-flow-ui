#include "imgui_impl_emscripten.h"

#include <GLES3/gl3.h>
#include <GLES3/gl3platform.h>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <emscripten/html5.h>
#include <emscripten.h>

int ems_init()
{
    std::cout << "ems init" << std::endl;
    EmscriptenWebGLContextAttributes attrs;
  emscripten_webgl_init_context_attributes(&attrs);
  attrs.enableExtensionsByDefault = 1;
  attrs.majorVersion = 2;
  attrs.minorVersion = 0;
  EMSCRIPTEN_WEBGL_CONTEXT_HANDLE context = emscripten_webgl_create_context( 0, &attrs );
  if (!context)
  {
    printf("Skipped: WebGL 2 is not supported.\n");
#ifdef REPORT_RESULT
    REPORT_RESULT(result);
#endif
    return 0;
  }
  emscripten_webgl_make_context_current(context);

    glClearColor(1.0f,1.0f,0.0,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    emscripten_webgl_commit_frame();
    sleep(10);
    return 0;
}
