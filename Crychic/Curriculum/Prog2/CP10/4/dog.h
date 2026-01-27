#ifndef DOG_H
#define DOG_H

#include "animal_base.h"

class dog:public animal_base
{
    public:
        dog(int h);
        void talk();
};

#endif