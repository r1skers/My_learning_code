#include "raytrace_v5.h"
#include <cmath>

double CRayTraceV5::RayTrace(CRayTrace::RayInfo ray, int* r, int* g, int* b,
    double* transparency)
{
    // Initialize color
    *r = GetRValue(bgcolor);
    *g = GetGValue(bgcolor);
    *b = GetBValue(bgcolor);

    // Initialize transparency
    *transparency = 1;

    // Ray casting and shading
    HitInfo hit;
    double t;
    if ((t = RayCast(ray, &hit)) != INFINITY)
    {
        // Set transparency to 0
        *transparency = 0;

        // Ambient light
        ShadingAmbientLight(hit, r, g, b);

        // Infinity light
        ShadingInfinityLight(hit, r, g, b);

        // Point light
        ShadingPointLight(ray, hit, r, g, b);

        // Reflection / Refraction
        ShadingReflectionRefraction(ray, hit, r, g, b, transparency);

        // Clamp
        *r = (*r > 255) ? 255 : *r;
        *g = (*g > 255) ? 255 : *g;
        *b = (*b > 255) ? 255 : *b;
    }
    return t;
}

void CRayTraceV5::ShadingReflectionRefraction(CRayTrace::RayInfo ray,
    CRayTrace::HitInfo hit, int* r, int* g, int* b, double* transparency)
{
    if (ray.count < tracelevel)
    {
        // Compute reflection / refraction parameters
        double refle_rate, refra_rate;
        vec3d refle_vec, refra_vec;
        bool refle_flag, refra_flag;
        ReflectionRefraction(ray, hit,
            &refle_rate, &refle_vec, &refle_flag,
            &refra_rate, &refra_vec, &refra_flag);

        // Refraction ray
    if (refra_flag == true)
    {
        double refra_t = 1.0;
        int refra_r, refra_g, refra_b;
        RayInfo refra_ray(hit.pos, refra_vec, -ray.inout, ray.count + 1);
        if (RayTrace(refra_ray, &refra_r, &refra_g, &refra_b, &refra_t) != INFINITY)
        {
            *r += (int)(refra_rate * refra_r);
            *g += (int)(refra_rate * refra_g);
            *b += (int)(refra_rate * refra_b);

            refra_t *= refra_rate;
        }
        *transparency = refra_t;
    }

        // Reflection ray
        if (refle_flag == true)
        {
            double refle_t;
            int refle_r, refle_g, refle_b;
            RayInfo refle_ray(hit.pos, refle_vec, ray.inout, ray.count + 1);
            if (RayTrace(refle_ray, &refle_r, &refle_g, &refle_b, &refle_t) != INFINITY)
            {
                *r += (int)(refle_rate * refle_r);
                *g += (int)(refle_rate * refle_g);
                *b += (int)(refle_rate * refle_b);
            }
        }
    }
}

void CRayTraceV5::ReflectionRefraction(CRayTrace::RayInfo ray,
    CRayTrace::HitInfo hit, double* refle_rate, vec3d* refle_vec,
    bool* refle_flag, double* refra_rate, vec3d* refra_vec, bool* refra_flag)
{
    *refle_flag = false;
    *refra_flag = false;

    // Base reflection
    *refle_rate = hit.reflection;

    // Refraction
    if (hit.transparency > 0.01)
    {
        double refraction;
        if (ray.inout == 1)
            refraction = hit.refraction;
        else
            refraction = 1.0 / hit.refraction;

        // cos1 = -N・E
        double cos1 = -(ray.ray.InnerProduct(hit.normal));
        double sin2 = 1.0 - cos1 * cos1;
        double k = 1.0 - sin2 / (refraction * refraction);
        if (k < 0.0)
        {
            // Total internal reflection
            *refle_rate = 1.0;
            *refra_flag = false;
        }
        else
        {
            double cos2 = sqrt(k);
            double refbuf=refraction * cos2 - cos1;
            double s1=refbuf/(refraction * cos2 + cos1);
            s1*=s1;
            double s2=(refraction* cos1 - cos2)/(refraction * cos1 + cos2);
            s2*=s2;
            double s=(s1 + s2) / 2.0;
            *refle_rate=s;
            double tr=1.0 - s;
            *refra_vec=(ray.ray-hit.normal*refbuf)/refraction;
            *refra_rate=tr*hit.transparency;
            *refra_flag=true;
        }
    }

    // Reflection
    if (hit.reflection > 0.01)
    {
        double en2 = 2 * (ray.ray.InnerProduct(hit.normal));
        *refle_vec = ray.ray - hit.normal * en2;
        *refle_flag = true;
    }
}
