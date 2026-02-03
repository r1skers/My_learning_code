#include "raytrace.h"
#include <cmath>
CRayTrace::CRayTrace(COLORREF bgcolor, int tracelevel, double envlight_r,
    double envlight_g, double envlight_b)
{
    this->bgcolor = bgcolor;
    this->tracelevel = tracelevel;
    this->envlight.r = envlight_r;
    this->envlight.g = envlight_g;
    this->envlight.b = envlight_b;
}
CRayTrace::~CRayTrace()
{
    while (0 < object_list.size())
    {
        CObjectBase* obj = object_list.back();
        object_list.pop_back();
        delete obj;
    }
}
void CRayTrace::AddObject(CObjectBase* obj)
{
    object_list.push_back(obj);
}
void CRayTrace::SetCamera(vec3d pos, vec3d target, double angle,
    double turnangle, int screen_cx, int screen_cy)
{
    camera.SetCamera(pos, target, angle, turnangle, screen_cx, screen_cy);
}
CBitmap& CRayTrace::Start()
{
    int screensize_cx, screensize_cy;
    camera.GetScreenSize(screensize_cx, screensize_cy);
    image.Create(screensize_cx * 2, screensize_cy * 2);
    vec3d viewpoint = camera.GetViewPoint();
    int sx = -screensize_cx;
    int ex = screensize_cx;
    for (int y = 0; y < image.Height(); y++)
    {
        BYTE* p = image.GetBits(0, y);
        int sy = screensize_cy - y;
        for (int x = sx; x < ex; x++)
        {
            vec3d pixelpos = camera.ScreenToAbsolute(x, sy);
            pixelpos -= viewpoint;
            pixelpos.UnitVec();
            int r, g, b;
            double transparency;
            RayTrace(RayInfo(viewpoint, pixelpos, 1, 1), &r, &g, &b,
                &transparency);
            p[2] = (BYTE)r;
            p[1] = (BYTE)g;
            p[0] = (BYTE)b;
            p += 3;
        }
    }
    return image;
}
double CRayTrace::RayTrace(CRayTrace::RayInfo ray, int* r, int* g, int* b,
    double* transparency)
{
    *r = GetRValue(bgcolor);
    *g = GetGValue(bgcolor);
    *b = GetBValue(bgcolor);
    *transparency = 1;
    HitInfo hit;
    double t;
    if ((t = RayCast(ray, &hit)) != INFINITY)
    {
        *transparency = 0;
        *r = (int)(hit.r * envlight.r);
        *g = (int)(hit.g * envlight.g);
        *b = (int)(hit.b * envlight.b);
        *r = (*r > 255) ? 255 : *r;
        *g = (*g > 255) ? 255 : *g;
        *b = (*b > 255) ? 255 : *b;
    }
    return t;
}
double CRayTrace::RayCast(CRayTrace::RayInfo ray, CRayTrace::HitInfo* phit)
{
    double lt = INFINITY;
    for (int i = 0; i < object_list.size(); i++)
    {
        CObjectBase* obj = object_list[i];
        double t = obj->RayCast(ray.viewpoint, ray.ray, ray.inout, lt);
        if (t < lt)
        {
            lt = t;
            phit->object = obj;
        }
    }
    if (lt < INFINITY)
    {
        phit->pos = ray.ray * lt + ray.viewpoint;
        COLORREF color = phit->object->GetColor(phit->pos);
        phit->r = GetRValue(color);
        phit->g = GetGValue(color);
        phit->b = GetBValue(color);
        phit->transparency = phit->object->GetTransparency(phit->pos);
        phit->reflection = phit->object->GetReflection(phit->pos);
        phit->refraction = phit->object->GetRefraction(phit->pos);
        phit->highlightdiaphragm = phit->object->GetHighlightDiaphragm(phit->pos);
        phit->highlight = phit->object->GetHighlight(phit->pos);
        phit->normal = phit->object->GetVecNormal(phit->pos) * ray.inout;
    }
    return lt;
}
