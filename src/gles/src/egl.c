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
#include "../include/egl.h"

/*-------------------------- 变量实现区 -------------------------*/
/**************************** 全局变量 ***************************/

/**************************** 文件变量 ***************************/
static EGLDisplay egldisplay;
static EGLSurface eglsurface;
#ifdef EGL_USE_X11
static Display *display;
#endif

/*------------------------ 局部函数声明区 -----------------------*/

/*-------------------------- 函数实现区 --------------------------*/
extern GLint EsInit(GLvoid)
{
    static const GLint s_configAttribs[] =
    {
        EGL_RENDERABLE_TYPE,    EGL_OPENGL_ES2_BIT,
        EGL_SURFACE_TYPE,       EGL_WINDOW_BIT,
        EGL_RED_SIZE,           8,
        EGL_GREEN_SIZE,         8,
        EGL_BLUE_SIZE,          8,
        EGL_ALPHA_SIZE,         0,
        EGL_SAMPLES,            0,
        EGL_DEPTH_SIZE,         8,
        EGL_NONE
    };

    GLint               numconfigs;
    EGLConfig           eglconfig;
    EGLContext          eglcontext;
    GLint               ContextAttribList[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE };

#ifdef EGL_USE_X11
    GLint               screen;
    Window              window;
    Window              rootwindow; 

    printf("XOpenDisplay \n");
    display = XOpenDisplay(NULL);
    assert(display != NULL);   

    printf("DefaultScreen [");
    screen = DefaultScreen(display);
    printf("%d]\n", screen);

    printf("RootWindow \n");
    rootwindow = RootWindow(display,screen);

    printf("eglGetDisplay (%d)\n", (GLint)display);
    egldisplay = eglGetDisplay ( display );
    assert(eglGetError() == EGL_SUCCESS);

    printf("Disp = %d \n",(GLint) egldisplay);

    printf("eglInitialize \n");
    eglInitialize(egldisplay, NULL, NULL);
    assert(eglGetError() == EGL_SUCCESS);

    printf("eglBindAPI \n");
    eglBindAPI(EGL_OPENGL_ES_API);

    printf("eglChooseConfig \n");
    eglChooseConfig(egldisplay, s_configAttribs, &eglconfig, 1, &numconfigs);
    assert(eglGetError() == EGL_SUCCESS);

    assert(numconfigs == 1);

    printf("XCreateSimpleWindow \n");
    window = XCreateSimpleWindow(display, rootwindow, 0, 0,
            800, 480, 0, 0, WhitePixel (display, screen));

    XMapWindow(display, window);

    printf("eglCreateWindowSurface \n");
    eglsurface = eglCreateWindowSurface(egldisplay, eglconfig, window, NULL);
    assert(eglGetError() == EGL_SUCCESS);

#else
    egldisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    eglInitialize(egldisplay, NULL, NULL);
    assert(eglGetError() == EGL_SUCCESS);
    eglBindAPI(EGL_OPENGL_ES_API);

    eglChooseConfig(egldisplay, s_configAttribs, &eglconfig, 1, &numconfigs);
    assert(eglGetError() == EGL_SUCCESS);
    assert(numconfigs == 1);

    eglsurface = eglCreateWindowSurface(egldisplay, eglconfig, open("/dev/fb0", O_RDWR), NULL);
    assert(eglGetError() == EGL_SUCCESS);
#endif

    eglcontext = eglCreateContext( egldisplay, eglconfig, EGL_NO_CONTEXT, ContextAttribList );
    assert(eglGetError() == EGL_SUCCESS);
    eglMakeCurrent(egldisplay, eglsurface, eglsurface, eglcontext);
    assert(eglGetError() == EGL_SUCCESS);

    return 1;
}

extern GLvoid EsDeInit(GLvoid)
{
    eglMakeCurrent(egldisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    assert(eglGetError() == EGL_SUCCESS);
    eglTerminate(egldisplay);
    assert(eglGetError() == EGL_SUCCESS);
    eglReleaseThread();
#ifdef EGL_USE_X11    
    XCloseDisplay(display);
#endif
}

GLint getWidth(GLvoid)
{
    GLint width = 0;
    eglQuerySurface(egldisplay, eglsurface, EGL_WIDTH, &width);
    return width;
}

GLint getHeight(GLvoid)
{
    GLint height = 0;
    eglQuerySurface(egldisplay, eglsurface, EGL_HEIGHT, &height);
    return height;
}

GLvoid ESSwapBuffers(GLvoid)
{
    eglSwapBuffers(egldisplay, eglsurface);
}
