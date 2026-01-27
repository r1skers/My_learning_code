#ifndef LINE_H
#define LINE_H

#include "object.h"
#include "bitmap.h"

class CLine: public CObject
{
    protected:
        int sx,sy;
        int ex,ey;
        
    public:
        CLine(int sx, int sy, int ex, int ey, COLORREF color);
        void draw(CBitmap &image);
};

#endif