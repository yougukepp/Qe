#include "GScreen.h" 

const string GScreen::vertexShaderFileName = "/home/lucid/test/gui/src/gles/glsl/vertex.glsl";
const string GScreen::fragmentShaderFileName = "/home/lucid/test/gui/src/gles/glsl/fragment.glsl";

GScreen::GScreen(int width, int height)
{
    this->width = width;
    this->width = height;

    /* egl = GEgl();*/
    program = GProgram(vertexShaderFileName, fragmentShaderFileName);
}

void GScreen::SetAttrbutes(vector<string> attributes)
{
    program.BindAttribLocation(attributes);
}

GLuint GScreen::GetProgramId(void)
{
    return program.GetId();
}

void GScreen::MainLoop(GCallBack draw)
{
    program.Link();
    program.Use();

    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    glEnable(GL_DEPTH_TEST);

    while(true)
    { 
        program.render(draw);
        egl.Swap();
    }

}

