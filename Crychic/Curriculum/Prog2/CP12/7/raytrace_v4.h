#ifndef RAYTRACE_V4_H
#define RAYTRACE_V4_H

#include "raytrace_v3.h"

class CRayTraceV4 : public CRayTraceV3
{
public:
    CRayTraceV4(COLORREF bgcolor, int tracelevel, double envlight_r,
        double envlight_g, double envlight_b)
        :CRayTraceV3(bgcolor, tracelevel, envlight_r, envlight_g,
            envlight_b) {;}
protected:
    virtual double RayTrace(CRayTrace::RayInfo ray, int* r, int* g,
        int* b, double* transparency);
    virtual void ShadingPointLight(CRayTrace::RayInfo ray,
        CRayTrace::HitInfo hit, int* r, int* g, int* b);
};

#endif
