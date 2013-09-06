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
#ifndef __G_POSITION_H__
#define __G_POSITION_H__

/***************************** 头文件 ****************************/
#include "GTypedef.h"


/***************************** 宏定义 ****************************/


/**************************** 类型定义 ***************************/
class GPosition{
public:
    enum Type{
        leftUp,
        rightUp,
        leftDown,
        rightDown,
        center,
    };
    GPosition();
    GPosition(Type t);
    GPosition(float x, float y, float z);

    float GetX(void);
    float GetY(void);
    float GetZ(void);
    float GetW(void);
    static int GetSize(void);

private:
    void SetXYZW(float x, float y, float z, float w);
    void SetXYZW(float x, float y, float z);

    float x;
    float y;
    float z;

    float w;
};





/*-------------------------- 接口声明区 -------------------------*/

/**************************** 全局变量 ***************************/


/**************************** 接口函数 ***************************/

#endif


