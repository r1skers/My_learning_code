#ifndef RAYTRACE_V3_H
#define RAYTRACE_V3_H

#include "raytrace_v2.h"

class CRayTraceV3 : public CRayTraceV2
{
public:
    CRayTraceV3(COLORREF bgcolor, int tracelevel, double envlight_r,
        double envlight_g, double envlight_b)
        :CRayTraceV2(bgcolor, tracelevel, envlight_r, envlight_g,
            envlight_b) {;}
    void SetPointLight(vec3d position, double r, double g, double b);
protected:
    virtual double RayTrace(CRayTrace::RayInfo ray, int* r, int* g,
        int* b, double* transparency);
    virtual void ShadingPointLight(CRayTrace::RayInfo ray,
        CRayTrace::HitInfo hit, int* r, int* g, int* b);

    struct PointLight
    {
        vec3d position;
        StrengthRGB strength;
    } point_light;
};

#endif
