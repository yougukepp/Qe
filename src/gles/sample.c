/*****************************************************************
 * Copyright(c) 2012, 武汉中原电子集团 应用电子研发中心
 * All rights reserved.
 * *
 * 文件名称:
 *
 * 摘要:
 *
 * 作者:
 *
 * 完成日期:
 *****************************************************************/
/*--------------------------- 预处理区 --------------------------*/
/***************************** 头文件 ****************************/
#include        "include/header.h"

#define         MAX_FRAME_NUMS          (9000)
#define         K                       (1024)
#define         BUF_SIZE                (10*K)

#define LINE_POINT              (2)

#define POSITION_INDEX          (0)
#define POSITION_SIZE           (4)
#define POSITION_OFFSET         (0)

#define COLOR_INDEX             (1)
#define COLOR_SIZE              (4)
#define COLOR_OFFSET            (4)

#define ATTR_SIZE               (POSITION_SIZE + COLOR_SIZE)


GLfloat gVertexData[] ={
     0.0f,  1.0f,  0.0f,  1.0f,       1.0f, 0.0f, 0.0f, 0.0f,
    -1.0f, -1.0f,  0.0f,  1.0f,       1.0f, 0.0f, 0.0f, 0.0f,
     1.0f, -1.0f,  0.0f,  1.0f,       1.0f, 0.0f, 0.0f, 0.0f,
     0.0f,  0.0f,  1.0f,  1.0f,       0.0f, 0.0f, 1.0f, 0.0f

};


GLchar *gAtrriTable[] =
{
    "g_vPosition",               /* position value in vertex shader */
    "g_vColor"                   /* color value in vertex shader */
};

GLubyte t1[] = {0, 1, 2};
GLubyte t2[] = {1, 2, 3};
GLubyte t3[] = {0, 3, 1};
GLubyte t4[] = {0, 2, 3};

/*-------------------------- 变量实现区 -------------------------*/
/**************************** 全局变量 ***************************/
/**************************** 文件变量 ***************************/

/*------------------------ 局部函数声明区 -----------------------*/
static void render(GLint);

/*-------------------------- 函数实现区 --------------------------*/
int main(int argc, char *argv[])
{
    char vertexBuf[BUF_SIZE] = {0};
    char fragmentBuf[BUF_SIZE] = {0};
    int programId = 0;
    int current_frame = 0;

    EsInit();

    ReadShaderSrc("./glsl/vertex.glsl", vertexBuf, BUF_SIZE);
    /* printf("vertex shader content:\n%s", vertexBuf); */

    ReadShaderSrc("./glsl/fragment.glsl", fragmentBuf, BUF_SIZE); 
    /* printf("fragment shader content:\n%s", fragmentBuf); */

    programId = EsLoaderProgram(vertexBuf, fragmentBuf);

    EsBindAttribLocation(programId, gAtrriTable, sizeof(gAtrriTable) / sizeof(GLfloat));

    EsLinkProgram(programId);
    glUseProgram(programId);

    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    glEnable(GL_DEPTH_TEST);

    while (current_frame < MAX_FRAME_NUMS)
    {
        render(programId);
        current_frame++;
        ESSwapBuffers();
    }

    EsDeInit();
    return 0;
}

static void render(GLint programId)
{
    glViewport(0, 0, getWidth(), getHeight());
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    static GLfloat fAngle = 0.0f;
    GLfloat scaleMat[16] = {0};
    GLfloat roataMat[16] = {0};
    GLint scaleMatIndex = 0;
    GLint roataMatIndex = 0;

#define PI (3.1415926)
    /* 0 -> 2*3.1415926 */
    if(fAngle >= 2 * PI)
    {
        fAngle = 0;
    }
    else
    {
        fAngle += 0.01f;
    }
    printf("angle:%f\n", fAngle/2/PI*360);
#undef PI

    scaleMat[ 0] = 0.7f;
    scaleMat[ 5] = 0.7f;
    scaleMat[10] = 0.7f;
    scaleMat[15] = 1.0f;

    roataMat[ 0] = cosf(fAngle);
    roataMat[ 2] = sinf(fAngle);
    roataMat[ 5] = 1.0f;
    roataMat[ 8] = -sinf(fAngle);
    roataMat[10] = cosf(fAngle);
    roataMat[15] = 1.0f;

    scaleMatIndex = glGetUniformLocation(programId, "g_scaleMat");
    roataMatIndex = glGetUniformLocation(programId, "g_roataMat");

    glUniformMatrix4fv(scaleMatIndex, 1, 0, scaleMat);
    glUniformMatrix4fv(roataMatIndex, 1, 0, roataMat);
    
    glVertexAttribPointer(POSITION_INDEX,
            POSITION_SIZE,
            GL_FLOAT,
            GL_FALSE,
            ATTR_SIZE * sizeof(GLfloat),
            gVertexData + POSITION_OFFSET);
    glEnableVertexAttribArray(POSITION_INDEX);

    glVertexAttribPointer( COLOR_INDEX,
            COLOR_SIZE,
            GL_FLOAT,
            GL_FALSE,
            ATTR_SIZE * sizeof(GLfloat),
            gVertexData + COLOR_OFFSET);
    glEnableVertexAttribArray(COLOR_INDEX);

    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, t1);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, t2);
    //glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, t3);
    //glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, t4);

    glDisableVertexAttribArray(POSITION_INDEX);
    glDisableVertexAttribArray(COLOR_INDEX);

}

