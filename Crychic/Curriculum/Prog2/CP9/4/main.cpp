#include "complex.h"
#include "bitmap.h"

COLORREF function_mandlebrot(int x, int y)
{
    Complex c,z;
    c.set((x-500)*0.004,((y-400)*0.004));
    z.set(0,0);

    for(int i=0;i<100;i++)
    {
        z=z*z+c;
        if(z.abs()>2.0)
        {
            return (COLORREF)(i*167772.15);
        }
    }
    return RGB(0,0,0);
}

int main(void)
{
    CBitmap image(640, 480);
    image.DrawFunctionImage(&function_mandlebrot);
    image.SaveBmp("mandlebrot.bmp");
}