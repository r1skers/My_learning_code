#ifndef OBJECT_BALL_H
#define OBJECT_BALL_H
#include "object_base.h"
class CObjectBall : public CObjectBase
{
public:
    CObjectBall(vec3d pos, double radius, COLORREF color, double transparency,
        double reflection, double refraction, int highlightdiaphragm,
        double highlight);
    virtual vec3d GetVecNormal(vec3d pos);
    virtual bool CheckInside(vec3d pos);
    virtual double RayCast(vec3d viewpoint, vec3d ray, int inout, double lt);
protected:
    double radius;
};
#endif
