#include "bitmap.h"

COLORREF function_check(int x, int y)
{
    return ((x%100-0.5*100)*(y%100-0.5*100)>0)? RGB(33,99,66):RGB(0,0,0);
}

int main(void)
{
    CBitmap image(640, 480);
    image.DrawFunctionImage(&function_check);
    image.SaveBmp("check.bmp");
}