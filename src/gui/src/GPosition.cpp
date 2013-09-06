#include "GPosition.h"

void GPosition::SetXYZW(float x, float y, float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

void GPosition::SetXYZW(float x, float y, float z)
{
    SetXYZW(x, y, z, 1);
}

GPosition::GPosition()
{
    SetXYZW(0, 0, 0);
}

GPosition::GPosition(Type t)
{
    switch(t)
    {
        case leftUp:
            {
                SetXYZW(-1, 1, 0);
                break;
            }
        case rightUp:
            {
                SetXYZW(1, 1, 0);
                break;
            }
        case leftDown:
            {
                SetXYZW(-1, -1, 0);
                break;
            }
        case rightDown:
            {
                SetXYZW(1, -1, 0);
                break;
            }
        case center:
            {
                SetXYZW(0, 0, 0);
                break;
            }
        default:
            {
                assert(0);
            }
    }
}

GPosition::GPosition(float x, float y, float z)
{
    SetXYZW(x, y, z);
} 

float GPosition::GetX(void)
{
//    cerr << "x" << x << "\n";
    return x;
}

float GPosition::GetY(void)
{
    return y;
}

float GPosition::GetZ(void)
{
    return z;
}

float GPosition::GetW(void)
{
    return w;
}

int GPosition::GetSize(void)
{
    return sizeof(x) + sizeof(y) + sizeof(z) + sizeof(w);
}

