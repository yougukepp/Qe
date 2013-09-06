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
#ifndef __G_COLOR_H__
#define __G_COLOR_H__

/***************************** 头文件 ****************************/
#include "GTypedef.h"


/***************************** 宏定义 ****************************/


/**************************** 类型定义 ***************************/
class GColor
{
public:
    enum Type{
        black,
        white,
        red,
        green,
        blue,
        yellow,
    };

    GColor(void);
    GColor(Type t);
    GColor(float r, float g, float b);

    float GetR(void);
    float GetG(void);
    float GetB(void);
    float GetA(void);
    static int GetSize(void);

private:
    void SetRGBA(float r, float g, float b, float a); 
    void SetRGBA(float r, float g, float b); 

    float r;
    float g;
    float b;
    float a;
};

    
class GColorTypeException:exception
{
public:
    const char* what() const throw();
private:

};

/*-------------------------- 接口声明区 -------------------------*/

/**************************** 全局变量 ***************************/


/**************************** 接口函数 ***************************/

#endif


