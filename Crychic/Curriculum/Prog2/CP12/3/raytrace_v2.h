#ifndef RAYTRACE_V2_H
#define RAYTRACE_V2_H

#include "raytrace.h"

class CRayTraceV2 : public CRayTrace
{
    public:
        CRayTraceV2(COLORREF bgcolor, int tracelevel, double envlight_r,
            double envlight_g, double envlight_b)
        :CRayTrace(bgcolor, tracelevel, envlight_r,
            envlight_g, envlight_b) {;}
            void SetInfinityLight(vec3d direction, double r, double g, double b);
    protected:
        virtual double RayTrace(CRayTrace::RayInfo ray, int* r, int* g, int* b,
            double* transparency);
        void ShadingAmbientLight(CRayTrace::HitInfo hit, int* r, int* g, int* b);
        void ShadingInfinityLight(CRayTrace::HitInfo hit, int* r, int* g, int* b);

        struct InfinityLight
        {
            vec3d direction;
            StrengthRGB strength;
        } inf_light;
};

#endif