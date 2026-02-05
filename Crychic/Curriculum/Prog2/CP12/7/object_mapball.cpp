#include "object_mapball.h"
#include <cmath>

const double PAI = 3.1415926535;

void CObjectMapBall::ConvertSpherical(vec3d pos, double* u, double* v)
{
    // Convert to local coordinates
    pos -= this->pos;

    double xxx = pos.x * pos.x + pos.z * pos.z;
    if (0 < pos.y)
        *u = atan(sqrt(xxx) / pos.y);
    else
        *u = atan(sqrt(xxx) / pos.y) + PAI;

    if (0 < pos.x)
        *v = atan(pos.z / pos.x) + 1.5 * PAI;
    else
        *v = atan(pos.z / pos.x) + 0.5 * PAI;
}

COLORREF CObjectMapBall::GetColor(vec3d pos)
{
    if (pImage)
    {
        double u, v;
        ConvertSpherical(pos, &u, &v);
        int iu = (int)(u / PAI * pImage->Height());
        int iv = (int)(v / (2 * PAI) * pImage->Width());
        BYTE* p = pImage->GetBits(iv, iu);
        return RGB(p[2], p[1], p[0]);
    }

    return CObjectBall::GetColor(pos);
}

double CObjectMapBall::GetTransparency(vec3d pos)
{
    if (pAlpha)
    {
        double u, v;
        ConvertSpherical(pos, &u, &v);
        int iu = (int)(u / PAI * pAlpha->Height());
        int iv = (int)(v / (2 * PAI) * pAlpha->Width());
        BYTE* p = pAlpha->GetBits(iv, iu);
        double r = 1 - p[2] / 255;
        double g = 1 - p[1] / 255;
        double b = 1 - p[0] / 255;
        return (r + g + b) / 3.0;
    }

    return CObjectBall::GetTransparency(pos);
}

vec3d CObjectMapBall::GetVecNormal(vec3d pos)
{
    if (pBump)
    {
        int w = pBump->Width();
        int h = pBump->Height();

        double s, t;
        ConvertSpherical(pos, &s, &t);
        int iu1 = (int)(s / PAI * h);
        int iv1 = (int)(t / (2 * PAI) * w);
        int iu2 = (iu1 + 1) % h;
        int iv2 = (iv1 + 1) % w;
        int iu0 = (iu1 - 1 + h) % h;
        int iv0 = (iv1 - 1 + w) % w;

        BYTE* pu0 = pBump->GetBits(iv1, iu0);
        BYTE* pu2 = pBump->GetBits(iv1, iu2);
        BYTE* pv0 = pBump->GetBits(iv0, iu1);
        BYTE* pv2 = pBump->GetBits(iv2, iu1);

        double Bu = (pu2[0] - pu0[0]) * 0.5 * 1;
        double Bv = (pv2[0] - pv0[0]) * 0.5 * 1;
        vec3d Ps(-cos(s) * cos(t), -sin(s), -cos(s) * sin(t));
        vec3d Pt(-sin(s) * cos(t), 0, -sin(s) * sin(t));

        vec3d N = Ps.OuterProduct(Pt);
        N = ((N.OuterProduct(Ps)) * Bv + (N.OuterProduct(Pt)) * Bu) / N.Length();
        N.UnitVec();
        return N;
    }

    return CObjectBall::GetVecNormal(pos);
}
