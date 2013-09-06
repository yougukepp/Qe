#include "GProgram.h"

GProgram::GProgram(void)
{
    ;
}

GProgram::GProgram(string vertexShaderFile, string fragmentShaderFile)
{
    vertexShader = GShader(GShader::vertex, vertexShaderFile);
    fragmentShader = GShader(GShader::fragment, fragmentShaderFile);

    id = glCreateProgram();
    assert(0 != id);

    glAttachShader(id, vertexShader.GetId());
    glAttachShader(id, fragmentShader.GetId());
}

void GProgram::Link(void)
{
    GLint linked;
    glLinkProgram(id);
    glGetProgramiv(id, GL_LINK_STATUS, &linked);
    if(!linked) 
    {
        GLint infoLen = 0;

        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &infoLen);

        if(infoLen > 1)
        {
            GLchar* infoLog = (GLchar *)malloc(sizeof(GLchar) * infoLen);

            glGetProgramInfoLog(id, infoLen, NULL, infoLog);
            cout << "Error linking program:" << infoLog << "\n";

            free(infoLog);
        }

        glDeleteProgram(id);
    }
}

void GProgram::BindAttribLocation(vector<string> attributes)
{ 
    for(int i=0; i<attributes.size(); i++)
    {
        glBindAttribLocation(id, i, attributes[i].c_str());
#ifdef G_DEBUG
        cout << attributes[i] << "\n";
#endif
    }

}

void GProgram::Use(void)
{
    glUseProgram(id);
}

void GProgram::render(GCallBack draw)
{
    draw.callfunc();
}

GLuint GProgram::GetId(void)
{
    return id;
}


