#ifndef OBJECT_BASE_H
#define OBJECT_BASE_H
#include "bitmap.h"
#include "vec3d.h"
class CObjectBase
{
public:
    CObjectBase() {}
    CObjectBase(vec3d pos, COLORREF color, double transparency,
        double reflection, double refraction, int highlightdiaphragm,
        double highlight)
    {
        this->pos = pos;
        this->color = color;
        this->transparency = transparency;
        this->reflection = reflection;
        this->refraction = refraction;
        this->highlightdiaphragm = highlightdiaphragm;
        this->highlight = highlight;
    }
    virtual ~CObjectBase() {}
    virtual COLORREF GetColor(vec3d pos) { return color; }
    virtual double GetTransparency(vec3d pos) { return transparency; }
    virtual double GetReflection(vec3d pos) { return reflection; }
    virtual double GetRefraction(vec3d pos) { return refraction; }
    virtual int GetHighlightDiaphragm(vec3d pos) { return highlightdiaphragm; }
    virtual double GetHighlight(vec3d pos) { return highlight; }
    virtual vec3d GetPos() { return pos; }
    virtual vec3d GetVecNormal(vec3d pos) = 0;
    virtual bool CheckInside(vec3d pos) = 0;
    virtual double RayCast(vec3d viewpoint, vec3d ray, int inout,
        double lt) = 0;
protected:
    COLORREF color;
    double transparency;
    double reflection;
    double refraction;
    int highlightdiaphragm;
    double highlight;
    vec3d pos;
};
#endif
