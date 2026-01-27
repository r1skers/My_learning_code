#ifndef MOUSE_H
#define MOUSE_H

#include "animal_base.h"

class mouse:public animal_base
{
    public:
        mouse(int h);
        void talk();
};

#endif