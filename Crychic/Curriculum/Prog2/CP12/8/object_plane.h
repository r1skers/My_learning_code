#ifndef OBJECT_PLANE_H
#define OBJECT_PLANE_H

#include "object_base.h"

class CObjectPlane : public CObjectBase
{
    public:
        CObjectPlane(vec3d pos,vec3d normal,COLORREF color,double transparency,
            double reflection,double refraction,
            int highlightdiaphragm,double highlight);
        CObjectPlane(vec3d pos,vec3d normal);
        vec3d GetVecNormal(vec3d pos){return normal;}
        bool CheckInside(vec3d pos);
        double RayCast(vec3d viewpoint,vec3d ray,int inout,double lt);
    private:
        vec3d normal;         
};

#endif