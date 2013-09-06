#include "GColor.h"

GColor::GColor(float r, float g, float b)
{
    SetRGBA(r, g, b);
}

GColor::GColor(GColor::Type t)
{
    switch(t)
    {
        case black:
            {
                SetRGBA(0, 0, 0);
                break;
            }
        case white:
            {
                SetRGBA(1, 1, 1);
                break;
            }
        case red:
            {
                SetRGBA(1, 0, 0);
                break;
            }
        case green:
            {
                SetRGBA(0, 1, 0);
                break;
            }
        case blue:
            {
                SetRGBA(0, 0, 1);
                break;
            }
        case yellow:
            {
                SetRGBA(1, 1, 0);
                break;
            }
        default:
            {
                throw GColorTypeException();
            }
    }
}

GColor::GColor(void)
{
    SetRGBA(1, 1, 1);
}

float GColor::GetR(void)
{
    return r;
}

float GColor::GetG(void)
{
    return g;
}

float GColor::GetB(void)
{
    return b;
}

float GColor::GetA(void)
{
    return a;
}

int GColor::GetSize(void)
{
    return sizeof(r) + sizeof(g) + sizeof(b) + sizeof(a);
}

void GColor::SetRGBA(float r, float g, float b, float a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void GColor::SetRGBA(float r, float g, float b)
{
    SetRGBA(r, g, b, 0);
}

const char* GColorTypeException::what() const throw()
{
    return "Get a Not Implenment Color Type.\n";
}

