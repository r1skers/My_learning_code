#ifndef OBJ_LIST_H
#define OBJ_LIST_H

#include "object.h"
#include "bitmap.h"

class CObjectList
{
    private:
        CObject* obj;
        CObjectList* next;
        CObjectList* prev;

    public:
        CObjectList(){next=prev=nullptr;obj=nullptr;};
        CObjectList* insert(CObject* obj);
        static void draw_all(CObjectList* head, CBitmap& image);
        static void remove_all(CObjectList* head);
};

#endif