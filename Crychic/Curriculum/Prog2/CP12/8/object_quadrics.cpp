#include "object_quadrics.h"
#include <cmath>

CObjectQuadrics::CObjectQuadrics(vec3d pos,
    double ppa,
    double ppb,
    double ppc,
    int pinoutflag,
    COLORREF color, double transparency, double reflection,
    double refraction, int highlightdiaphragm, double highlight)
    : CObjectBase(pos, color, transparency, reflection,
        refraction, highlightdiaphragm, highlight)
{
    pa = ppa;
    pb = ppb;
    pc = ppc;
    inoutflag = pinoutflag;
}

CObjectQuadrics::~CObjectQuadrics()
{
    BlockPlaneList_Release();
}

vec3d CObjectQuadrics::GetVecNormal(vec3d pos)
{
    double nx = 2.0 * pos.x / pa;
    double ny = -1.0 / pb;
    double nz = -2.0 * pos.z / pc;

    vec3d N = vec3d(nx, ny, nz) * (-inoutflag);
    N.UnitVec();

    return N;
}

bool CObjectQuadrics::CheckInside(vec3d pos)
{
    return (0 >= (pos.x * pos.x / pa - pos.y / pb - pos.z * pos.z / pc));
}

double CObjectQuadrics::RayCast(vec3d viewpoint, vec3d ray, int inout, double lt)
{
    double px = ray.x;
    double py = ray.y;
    double pz = ray.z;
    double qx = viewpoint.x;
    double qy = viewpoint.y;
    double qz = viewpoint.z;

    double a = px * px / pa - pz * pz / pc;
    double b = 2.0 * px * qx / pa - py/pb - 2.0 * pz * qz / pc;
    double c = qx * qx / pa - qy / pb - qz * qz / pc;

    double d = b * b - 4 * a * c;
    if (d >= 0)
    {
        double sqrtd = sqrt(d);
        double t1 = (-b + sqrtd) / (2 * a);
        double t2 = (-b - sqrtd) / (2 * a);

        vec3d p1 = viewpoint + ray * t1;
        vec3d p2 = viewpoint + ray * t2;
        if (BlockPlane_CheckInside(p1) == false) t1 = INFINITY;
        if (BlockPlane_CheckInside(p2) == false) t2 = INFINITY;

        double t;
        if (t1 == INFINITY && t2 == INFINITY) { return lt; }
        else { t = (t1 < t2) ? t1 : t2; }

        if (t > 0.01 && t < lt)
        {
            return t;
        }
    }

    return lt;
}
