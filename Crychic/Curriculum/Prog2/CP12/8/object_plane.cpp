#include "object_plane.h"

CObjectPlane::CObjectPlane(vec3d pos,vec3d normal,COLORREF color,double transparency,
    double reflection,double refraction,
    int highlightdiaphragm,double highlight)
    :CObjectBase(pos,color,transparency,reflection,refraction,
        highlightdiaphragm,highlight)
{
    this->normal = normal;
}

CObjectPlane::CObjectPlane(vec3d pos,vec3d normal)
    :CObjectBase()
{
    this->pos = pos;
    this->normal = normal;
}

bool CObjectPlane::CheckInside(vec3d pos)
{
    return (0>=normal.InnerProduct(this->pos-pos));
}

double CObjectPlane::RayCast(vec3d viewpoint,vec3d ray,int inout,double lt)
{
    double d=ray.InnerProduct(normal);
    if(d!=0.0)
    {
        double q=-(normal.InnerProduct(pos));
        double t=-((normal.InnerProduct(viewpoint)+q)/(d));
        if(t>0.01&&t<lt)
            return t;
    }
    return lt;
}