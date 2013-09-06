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
#ifndef __G_VERTEX_H__
#define __G_VERTEX_H__

/***************************** 头文件 ****************************/
#include "GTypedef.h"
#include "GPosition.h"
#include "GColor.h"


/***************************** 宏定义 ****************************/


/**************************** 类型定义 ***************************/
class GVertex
{
public:
    GVertex(void);
    GVertex(GPosition& p);
    GVertex(GPosition& p, GColor& c); 
    
    float GetX(void);
    float GetY(void);
    float GetZ(void);
    float GetW(void);
    float GetR(void);
    float GetG(void);
    float GetB(void);
    float GetA(void);

private:
    void SetPC(GPosition& p, GColor& c);

    GPosition p;
    GColor c;
};

/*-------------------------- 接口声明区 -------------------------*/

/**************************** 全局变量 ***************************/


/**************************** 接口函数 ***************************/

#endif

