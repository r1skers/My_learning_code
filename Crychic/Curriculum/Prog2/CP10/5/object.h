#ifndef OBJECT_H
#define OBJECT_H

#include "bitmap.h"

class CObject
{
    protected:
        COLORREF color;
    public:
        CObject(COLORREF color){this->color=color;};
        virtual ~CObject(){};

        virtual void draw(CBitmap &image)=0;
};

#endif