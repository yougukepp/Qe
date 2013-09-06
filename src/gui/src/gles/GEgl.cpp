#include "GEgl.h"

GEgl::GEgl(void)
{
    static const GLint configAttribs[] =
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

    GLint               numConfigs;
    EGLConfig           eglConfig;
    EGLContext          eglContext;

    GLint               contextAttribList[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE };

#ifdef EGL_USE_X11
    GLint               screen;
    Window              window;
    Window              rootWindow; 

#ifdef G_DEBUG
    cout << "XOpenDisplay \n";
#endif
    display = XOpenDisplay(NULL);
    assert(display != NULL);   

#ifdef G_DEBUG
    cout << "DefaultScreen [";
#endif
    screen = DefaultScreen(display);
#ifdef G_DEBUG
    cout << screen <<"]\n";
    cout << "RootWindow \n";
#endif
    rootWindow = RootWindow(display,screen);

#ifdef G_DEBUG
    cout << "eglGetDisplay (" << (GLint)display << ")\n";
#endif
    egldisplay = eglGetDisplay ( display );
    assert(eglGetError() == EGL_SUCCESS);

#ifdef G_DEBUG
    cout << "Disp = " << (GLint)egldisplay << " \n";

    cout << "eglInitialize \n";
#endif
    eglInitialize(egldisplay, NULL, NULL);
    assert(eglGetError() == EGL_SUCCESS);

#ifdef G_DEBUG
    cout << "eglBindAPI \n";
#endif
    eglBindAPI(EGL_OPENGL_ES_API);

#ifdef G_DEBUG
    cout << "eglChooseConfig \n";
#endif
    eglChooseConfig(egldisplay, configAttribs, &eglConfig, 1, &numConfigs);
    assert(eglGetError() == EGL_SUCCESS);

    assert(numConfigs == 1);

#ifdef G_DEBUG
    cout << "XCreateSimpleWindow \n";
#endif
    window = XCreateSimpleWindow(display, rootWindow, 0, 0,
            800, 480, 0, 0, WhitePixel (display, screen));

    XMapWindow(display, window);

#ifdef G_DEBUG
    cout << "eglCreateWindowSurface \n";
#endif
    eglsurface = eglCreateWindowSurface(egldisplay, eglConfig, window, NULL);
    assert(eglGetError() == EGL_SUCCESS);

#else
    egldisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    eglInitialize(egldisplay, NULL, NULL);
    assert(eglGetError() == EGL_SUCCESS);
    eglBindAPI(EGL_OPENGL_ES_API);

    eglChooseConfig(egldisplay, configAttribs, &eglConfig, 1, &numConfigs);
    assert(eglGetError() == EGL_SUCCESS);
    assert(numConfigs == 1);

    eglsurface = eglCreateWindowSurface(egldisplay, eglConfig, open("/dev/fb0", O_RDWR), NULL);
    assert(eglGetError() == EGL_SUCCESS);
#endif

    eglContext = eglCreateContext( egldisplay, eglConfig, EGL_NO_CONTEXT, contextAttribList );
    assert(eglGetError() == EGL_SUCCESS);
    eglMakeCurrent(egldisplay, eglsurface, eglsurface, eglContext);
    assert(eglGetError() == EGL_SUCCESS);
}

void GEgl::Swap(void)
{
    eglSwapBuffers(egldisplay, eglsurface);
}

