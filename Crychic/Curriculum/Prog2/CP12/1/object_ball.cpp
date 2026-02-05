#include "object_ball.h"
#include <cmath>

CObjectBall::CObjectBall(vec3d pos, double radius, COLORREF color,
    double transparency, double reflection, double refraction,
    int highlightdiaphragm, double highlight)
    : CObjectBase(pos, color, transparency, reflection, refraction,
        highlightdiaphragm, highlight)
{
    this->radius = radius;
}

vec3d CObjectBall::GetVecNormal(vec3d pos)
{
    vec3d n = pos - this->GetPos();
    n.UnitVec();
    return n;
}

bool CObjectBall::CheckInside(vec3d pos)
{
    return (radius >= (pos - this->pos).Length());
}

double CObjectBall::RayCast(vec3d viewpoint, vec3d ray, int inout, double lt)
{
    vec3d buf = viewpoint - pos;
    double b = ray.InnerProduct(buf) * 2.0;
    double c = buf.InnerProduct(buf) - radius * radius;
    double d = b * b - 4 * c;
    if (d >= 0)
    {
        double t = (-b - inout * sqrt(d)) / 2;
        if (t > 0.01 && t < lt)
        {
            return t;
        }
    }

    return lt;
}