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
#ifndef __G_PROGRAM_H__
#define __G_PROGRAM_H__

/***************************** 头文件 ****************************/
#include "GTypedef.h"
#include "GCallBack.h"
#include "GShader.h"


/***************************** 宏定义 ****************************/


/**************************** 类型定义 ***************************/
class GProgram{
public:
    GProgram(void);
    GProgram(string vertexShaderFile, string fragmentShaderFile);
    void BindAttribLocation(vector<string> attributes);
    void Link(void);
    void Use(void);
    void render(GCallBack draw);
    GLuint GetId(void);
private:
    GLuint id; 
    GShader vertexShader;
    GShader fragmentShader;
};





/*-------------------------- 接口声明区 -------------------------*/

/**************************** 全局变量 ***************************/


/**************************** 接口函数 ***************************/

#endif


