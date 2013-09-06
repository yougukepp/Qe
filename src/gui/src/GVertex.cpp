#include "GVertex.h"

GVertex::GVertex(void)
{
    p = GPosition(GPosition::center);
    c = GColor(GColor::white);
    SetPC(p, c);
}

GVertex::GVertex(GPosition& p)
{
    c = GColor(GColor::white);
    SetPC(p, c);
}

GVertex::GVertex(GPosition& p, GColor& c)
{
    SetPC(p, c);
}

void GVertex::SetPC(GPosition& p, GColor& c)
{
    this->p = p;
    this->c = c;
}

float GVertex::GetX(void)
{
    //cerr << p.GetX() << "\n";
    return p.GetX();
}

float GVertex::GetY(void)
{
    return p.GetY();
}

float GVertex::GetZ(void)
{
    return p.GetZ();
}

float GVertex::GetW(void)
{
    return p.GetW();
}

float GVertex::GetR(void)
{
    return c.GetR();
}

float GVertex::GetG(void)
{
    return c.GetG();
}

float GVertex::GetB(void)
{
    return c.GetB();
}

float GVertex::GetA(void)
{
    return c.GetA();
}

