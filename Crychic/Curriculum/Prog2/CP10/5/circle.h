#ifndef CIRCLE_H
#define CIRCLE_H

#include "object.h"
#include "bitmap.h"

class CCircle: public CObject
{
    protected:
        int ox,oy;
        int r;
        
    public:
        CCircle(int ox, int oy, int r, COLORREF color);
        void draw(CBitmap &image);
};

#endif