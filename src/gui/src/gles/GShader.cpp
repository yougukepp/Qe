#include "GShader.h"
    
GShader::GShader(void)
{
    ;
}

GShader::GShader(Type t, string srcFile)
{
    // 读取着色器代码
    string srcStr;
    ifstream src(srcFile.c_str(), std::ios::in | std::ios::binary);
    assert(0 != src);
    src.seekg(0, std::ios::end);
    srcStr.resize(src.tellg());
    src.seekg(0, std::ios::beg);
    src.read(&srcStr[0], srcStr.size());
    src.close();

    // 编译着色器
    id = glCreateShader(t);
    assert(0 != id); 
    
    const char *cSrcStr = srcStr.c_str();
    glShaderSource(id, 1, &cSrcStr, NULL);
    glCompileShader(id);

    GLint compiled;
    glGetShaderiv(id, GL_COMPILE_STATUS, &compiled);
    if(!compiled)
    {
        GLint infoLen = 0;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &infoLen);

        if(infoLen > 1)
        {
            GLchar* infoLog = (GLchar *)malloc(sizeof(GLchar) * infoLen);

            glGetShaderInfoLog (id, infoLen, NULL, infoLog);
            cout << "Error compiling shader:" << infoLog << "\n";
            cout << "shader content:\n" << srcStr;

            free(infoLog);
        }

        glDeleteShader(id);
    }
}

GLuint GShader::GetId(void)
{
    return id;
}

const char* GShaderCreateException::what() const throw()
{
    return "Not Implenment GShader.\n";
}

