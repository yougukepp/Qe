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
#ifndef __G_PRIMITIVE_H__
#define __G_PRIMITIVE_H__

/***************************** 头文件 ****************************/
#include "GTypedef.h"
#include "GVertex.h"


/***************************** 宏定义 ****************************/


/**************************** 类型定义 ***************************/
class GPrimitive{
public:
    GPrimitive(void){};
    void draw(void);
    void AddVertex(GVertex& vertex);
    void AddIndex(GLuint& index);

private:
    vector<GVertex> vertexs;
    vector<GLuint> indexes;
};





/*-------------------------- 接口声明区 -------------------------*/

/**************************** 全局变量 ***************************/


/**************************** 接口函数 ***************************/

#endif


