#include "gui.h"

static const int width = 800;
static const int height = 480;
static GLuint programId;
static void draw(void);

static const int gPositionIndex = 0;
static const int gPositionSize = 4;
static const int gPositionOffset = 0;
static const int gColorIndex = 1;
static const int gColorSize = 4;
static const int gColorOffset = 4;
static const int gAttributeSize = (gPositionSize + gColorSize);

int main(int argc, char *argv[])
{
    vector<string> programAttributes;
    GCallBack callBackFunc= GCallBack(draw);

    try{
        programAttributes.push_back("g_vPosition");
        programAttributes.push_back("g_vColor");

        GScreen s = GScreen(width, height);
        s.SetAttrbutes(programAttributes);
        programId = s.GetProgramId();
        s.MainLoop(callBackFunc);
    }
    catch(GColorTypeException e)
    {
        cerr<<e.what();
    }
    catch(GShaderCreateException e)
    {
        cerr<<e.what();
    }
    catch(exception e)
    {
        cerr<<e.what()<<"\n";
    }

    return 0;
}

static GLfloat gVertexData[] ={
     0.0f,  1.0f,  0.0f,  1.0f,       1.0f, 0.0f, 0.0f, 0.0f,
    -1.0f, -1.0f,  0.0f,  1.0f,       0.0f, 1.0f, 0.0f, 0.0f,
     1.0f, -1.0f,  0.0f,  1.0f,       0.0f, 0.0f, 1.0f, 0.0f,
     0.0f,  0.0f,  1.0f,  1.0f,       1.0f, 1.0f, 1.0f, 0.0f
};

static GLubyte t1[] = {0, 1, 2};
static GLubyte t2[] = {1, 2, 3};
static GLubyte t3[] = {0, 3, 1};
static GLubyte t4[] = {0, 2, 3};

void draw(void)
{
#if 1

    GLfloat scaleMat[16] = {0};
    GLfloat roataMat[16] = {0};
    GLint scaleMatIndex = 0;
    GLint roataMatIndex = 0;

    scaleMat[ 0] = 1.0f;
    scaleMat[ 5] = 1.0f;
    scaleMat[10] = 1.0f;
    scaleMat[15] = 1.0f;

    roataMat[ 0] = 1.0f;
    roataMat[ 5] = 1.0f;
    roataMat[10] = 1.0f;
    roataMat[15] = 1.0f;

    scaleMatIndex = glGetUniformLocation(programId, "g_scaleMat");
    roataMatIndex = glGetUniformLocation(programId, "g_roataMat");

    glUniformMatrix4fv(scaleMatIndex, 1, 0, scaleMat);
    glUniformMatrix4fv(roataMatIndex, 1, 0, roataMat);

    GPosition p1,p2;
    GColor c;
    GVertex v1;
    GVertex v2;

    GLines line1 = GLines();
    GLines line2 = GLines();

    c = GColor(GColor::white);

    p1 = GPosition(GPosition::leftUp);
    p2 = GPosition(GPosition::rightDown);
    v1 = GVertex(p1, c);
    v2 = GVertex(p2, c);
    line1.AddVertex(v1);
    line1.AddVertex(v2);

    p1 = GPosition(GPosition::rightUp);
    p2 = GPosition(GPosition::leftDown);
    v1 = GVertex(p1, c);
    v2 = GVertex(p2, c);
    line2.AddVertex(v1);
    line2.AddVertex(v2);

    line1.draw();
    line2.draw();
#else
    glViewport(0, 0, width, height);
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

    glVertexAttribPointer(gPositionIndex,
            gPositionSize,
            GL_FLOAT,
            GL_FALSE,
            gAttributeSize * sizeof(GLfloat),
            gVertexData + gPositionOffset);
    glEnableVertexAttribArray(gPositionIndex);

    glVertexAttribPointer( gColorIndex,
            gColorSize,
            GL_FLOAT,
            GL_FALSE,
            gAttributeSize * sizeof(GLfloat),
            gVertexData + gColorOffset);
    glEnableVertexAttribArray(gColorIndex);

    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, t1);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, t2);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, t3);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, t4);

    glDisableVertexAttribArray(gPositionIndex);
    glDisableVertexAttribArray(gColorIndex);
#endif
}


