#ifndef RAYTRACE_V5_H
#define RAYTRACE_V5_H

#include "raytrace_v4.h"

class CRayTraceV5 : public CRayTraceV4
{
public:
    CRayTraceV5(COLORREF bgcolor, int tracelevel, double envlight_r,
        double envlight_g, double envlight_b)
        : CRayTraceV4(bgcolor, tracelevel, envlight_r, envlight_g, envlight_b) {;}

protected:
    virtual double RayTrace(CRayTrace::RayInfo ray, int* r, int* g, int* b,
        double* transparency);

    void ShadingReflectionRefraction(CRayTrace::RayInfo ray, CRayTrace::HitInfo hit,
        int* r, int* g, int* b, double* transparency);

    void ReflectionRefraction(CRayTrace::RayInfo ray, CRayTrace::HitInfo hit,
        double* refle_rate, vec3d* refle_vec, bool* refle_flag,
        double* refra_rate, vec3d* refra_vec, bool* refra_flag);
};

#endif
