#ifndef OBJECT_MAPBALL_H
#define OBJECT_MAPBALL_H

#include "object_ball.h"
#include "bitmap.h"

class CObjectMapBall : public CObjectBall
{
public:
    CObjectMapBall(vec3d pos, double radius, COLORREF color, double transparency,
        double reflection, double refraction, int highlightdiaphragm,
        double highlight, CBitmap* pImage, CBitmap* pAlpha, CBitmap* pBump)
        : CObjectBall(pos, radius, color, transparency, reflection, refraction,
            highlightdiaphragm, highlight)
    {
        this->pImage = pImage;
        this->pAlpha = pAlpha;
        this->pBump = pBump;
    }

    COLORREF GetColor(vec3d pos);
    double GetTransparency(vec3d pos);
    vec3d GetVecNormal(vec3d pos);

    void SetImagePtr(CBitmap* ptr) { pImage = ptr; }
    void SetAlphaPtr(CBitmap* ptr) { pAlpha = ptr; }
    void SetBumpPtr(CBitmap* ptr) { pBump = ptr; }

private:
    void ConvertSpherical(vec3d pos, double* u, double* v);

    CBitmap* pImage;
    CBitmap* pAlpha;
    CBitmap* pBump;
};

#endif
