/*****************************************************************
 * Copyright(c) 2012, 武汉中原电子集团 应用电子研发中心
 * All rights reserved.
 * *
 * 文件名称:
 *
 * 摘要:
 *
 * 作者:PengPeng <yougukepp@gmail.com>
 *
 * 完成日期:
 *****************************************************************/
/*--------------------------- 预处理区 --------------------------*/
#ifndef __G_SCREEN_H__
#define __G_SCREEN_H__

/***************************** 头文件 ****************************/
#include "GTypedef.h"
#include "GCallBack.h"
#include "GEgl.h"
#include "GShader.h"
#include "GProgram.h"


/***************************** 宏定义 ****************************/


/**************************** 类型定义 ***************************/
class GScreen{
public:
    GScreen(int width, int height); 
    void SetAttrbutes(vector<string> attributes);
    void MainLoop(GCallBack draw);
    GLuint GetProgramId(void);

private:
    int width;
    int height;
    GEgl egl;
    GProgram program;

    static const string vertexShaderFileName;
    static const string fragmentShaderFileName;
};





/*-------------------------- 接口声明区 -------------------------*/

/**************************** 全局变量 ***************************/


/**************************** 接口函数 ***************************/

#endif


