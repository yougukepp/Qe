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
#ifndef __G_SHADER_H__
#define __G_SHADER_H__

/***************************** 头文件 ****************************/
#include "../GTypedef.h"


/***************************** 宏定义 ****************************/


/**************************** 类型定义 ***************************/
class GShader{
public:
    enum Type{
        vertex = GL_VERTEX_SHADER,
        fragment = GL_FRAGMENT_SHADER,
    };
    GShader(void);
    GShader(Type t, string src);
    GLuint GetId(void);

private:
    GLuint id;
};

class GShaderCreateException:exception
{
public:
    const char* what() const throw();
private:
};



/*-------------------------- 接口声明区 -------------------------*/

/**************************** 全局变量 ***************************/


/**************************** 接口函数 ***************************/

#endif


