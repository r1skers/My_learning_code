#ifndef BILIST_H
#define BILIST_H
#include <iostream>
#include "list.h"

class bilist : public list{
    public:
        list* prev;
    public:
        bilist();
        bilist* insert();
        void remove();
};

#endif