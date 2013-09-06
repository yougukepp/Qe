#include "GCallBack.h"

GCallBack::GCallBack(void)
{
    cerr << "Not ImplentMent GCallBack default constructor.\n";
}

GCallBack::GCallBack(GCallBackFuncPtr funcPtr)
{
    this->funcPtr = funcPtr;
}

void GCallBack::callfunc(void)
{
    funcPtr();
}

