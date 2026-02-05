#include "raytrace_v2.h"
#include <cmath>

void CRayTraceV2::SetInfinityLight(vec3d direction, double r, double g, double b)
{
    inf_light.direction = direction;
    inf_light.strength.r = r;
    inf_light.strength.g = g;
    inf_light.strength.b = b;
}

double CRayTraceV2::RayTrace(CRayTrace::RayInfo ray, int* r, int* g, int* b,
    double* transparency)
{
    // 色を初期化
    *r = GetRValue(bgcolor);
    *g = GetGValue(bgcolor);
    *b = GetBValue(bgcolor);

    // 視線透過度を初期化
    *transparency = 1;

    // 交点を計算してシェーディング
    HitInfo hit;
    double t;
    if ((t = RayCast(ray, &hit)) != INFINITY)
    {
        // 視線透過度を 0 に設定
        *transparency = 0;

        // 環境光の作用を計算
        ShadingAmbientLight(hit, r, g, b);

        // 無限遠光源の作用を計算
        ShadingInfinityLight(hit, r, g, b);

        // 上限飽和
        *r = (*r > 255) ? 255 : *r;
        *g = (*g > 255) ? 255 : *g;
        *b = (*b > 255) ? 255 : *b;
    }
    return t;
}

void CRayTraceV2::ShadingAmbientLight(CRayTrace::HitInfo hit, int* r, int* g, int* b)
{
    *r = (int)(hit.r * envlight.r);
    *g = (int)(hit.g * envlight.g);
    *b = (int)(hit.b * envlight.b);
}

void CRayTraceV2::ShadingInfinityLight(CRayTrace::HitInfo hit, int* r, int* g, int* b)
{
    // 反射光の強さを計算
    double ln = hit.normal.InnerProduct(inf_light.direction);
    ln = (ln < 0) ? 0 : ln;

    // 光源を適用
    *r += (int)(hit.r * inf_light.strength.r * ln);
    *g += (int)(hit.g * inf_light.strength.g * ln);
    *b += (int)(hit.b * inf_light.strength.b * ln);
}
