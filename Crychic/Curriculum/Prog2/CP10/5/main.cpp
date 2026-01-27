#include "bitmap.h"
#include "object_list.h"
#include "line.h"
#include "circle.h"

const int WIDTH=640;
const int HEIGHT=480;

inline double drand(){
    return rand()/(1.0+(double)RAND_MAX);
}

int main(){
    CBitmap image(WIDTH, HEIGHT);

    CObjectList* list=new CObjectList;
    list->insert(new CLine(10, 10, WIDTH-10, HEIGHT-10, RGB(255, 255, 255)));
    list->insert(new CLine(WIDTH-10, 10, 10,HEIGHT-10, RGB(255, 255, 255)));

    for(int i=0;i<50;i++)
    {
        int ix=drand()*WIDTH;
        int iy=drand()*HEIGHT;
        int R=drand()*255;
        int G=drand()*255;
        int B=drand()*255;
        list->insert(new CCircle(ix, iy, 20, RGB(R, G, B)));
    }
    CObjectList::draw_all(list, image);
    CObjectList::remove_all(list);

    image.SaveBmp("image.bmp");
}