#include <iostream>
#include "line.h"

CLine::CLine(int sx, int sy, int ex, int ey, COLORREF color)
    : CObject(color)
{
    this->sx = sx;
    this->sy = sy;
    this->ex = ex;
    this->ey = ey;
}

void CLine::draw(CBitmap& image)
{
    int dx,dy;
    int step;
    int E;

    dx=(ex>sx)?(ex - sx):(sx - ex);
    dy=(ey>sy)?(ey - sy):(sy - ey);

    if(dx>=dy){
        if(ex<sx){
            int bufx=sx;
            int bufy=sy;
            sx=ex;
            sy=ey;
            ex=bufx;
            ey=bufy;
        }
        step=(ey>sy)?1:-1;
        E=dx>>1;
        do{
            image.SetPixel(sx, sy, color);
            if((E-=dy)<0){
                sy+=step;
                E+=dx;
            }
        }while(++sx<=ex);;
}
    else{
        if(ey<sy){
            int bufx=sx;
            int bufy=sy;
            sx=ex;
            sy=ey;
            ex=bufx;
            ey=bufy;
        }
        step=(ex>sx)?1:-1;
        E=dy>>1;
        do{
            image.SetPixel(sx, sy, color);
            if((E-=dx)<0){
                sx+=step;
                E+=dy;
            }
        }while(++sy<=ey);
    }
}