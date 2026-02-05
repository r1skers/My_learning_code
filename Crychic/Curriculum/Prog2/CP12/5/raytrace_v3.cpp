#include "raytrace_v3.h"
#include <cmath>

void CRayTraceV3::SetPointLight(vec3d position, double r, double g, double b)
{
    point_light.position = position;
    point_light.strength.r = r;
    point_light.strength.g = g;
    point_light.strength.b = b;
}

double CRayTraceV3::RayTrace(CRayTrace::RayInfo ray, int* r, int* g,
    int* b, double* transparency)
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

        // Clamp
        *r = (*r > 255) ? 255 : *r;
        *g = (*g > 255) ? 255 : *g;
        *b = (*b > 255) ? 255 : *b;
    }
    return t;
}

void CRayTraceV3::ShadingPointLight(CRayTrace::RayInfo ray,
    CRayTrace::HitInfo hit, int* r, int* g, int* b)
{
    // Direction to point light
    vec3d direction = point_light.position - hit.pos;
    direction.UnitVec();

    // Diffuse reflection
    double ln = hit.normal.InnerProduct(direction);
    ln = (ln < 0) ? 0 : ln;

    // Lambert's cosine law
    *r += (int)(hit.r * point_light.strength.r * ln);
    *g += (int)(hit.g * point_light.strength.g * ln);
    *b += (int)(hit.b * point_light.strength.b * ln);

    // Highlight
    double ln2 = ln * 2;
    vec3d h = direction - hit.normal * ln2;
    double hv = h.InnerProduct(ray.ray);
    double level = 1;
    if (hv > 0)
    {
        for (int i = 0; i < hit.highlightdiaphragm; i++)
            level *= hv;
    }
    else
    {
        level = 0.0;
    }

    *r += (int)(255 * hit.highlight * level * point_light.strength.r);
    *g += (int)(255 * hit.highlight * level * point_light.strength.g);
    *b += (int)(255 * hit.highlight * level * point_light.strength.b);
}
