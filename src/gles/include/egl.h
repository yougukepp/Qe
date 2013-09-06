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
/* use __MX_EGL__ not use __EGL__!!!  */
#ifndef         __MX_EGL__
#define         __MX_EGL__
/***************************** 头文件 ****************************/
#include	<assert.h>
#include	<stdio.h>
#include        <fcntl.h>
#include        <EGL/egl.h>
#include        <GLES2/gl2.h>

/***************************** 宏定义 ****************************/

/*-------------------------- 接口声明区 -------------------------*/

/**************************** 全局变量 ***************************/

/*--------------------------- 接口函数 --------------------------*/
extern EGLint EsInit(GLvoid);
extern GLvoid EsDeInit(GLvoid);
extern GLint getWidth(GLvoid);
extern GLint getHeight(GLvoid);
extern GLvoid ESSwapBuffers(GLvoid);

#endif
