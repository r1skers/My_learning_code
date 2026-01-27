#ifndef CAT_H
#define CAT_H

#include "animal_base.h"

class cat: public animal_base
{
    public:
        cat(int h);
        void talk();
};

#endif