#include "vec3d.h"
#include "bitmap.h"
#include "raytrace_v5.h"
#include "object_ball.h"
#include "object_plane.h"
#include "object_mapball.h"
#include "complex.h"
#include <cmath>
#include "object_quadrics.h"

const double PAI = 3.141592;

const int QBLOCK_XMIN=-150;
const int QBLOCK_XMAX=150;
const int QBLOCK_ZMIN=-150;
const int QBLOCK_ZMAX=150;

const int PBLOCK_XMIN=-500;
const int PBLOCK_XMAX=500;
const int PBLOCK_ZMIN=-500;
const int PBLOCK_ZMAX=500;

COLORREF function_check(int x, int y)
{
    return ((x%100-0.5*100)*(y%100-0.5*100) > 0) ? RGB(255,255,255) : RGB(0,0,0);
}

COLORREF function_mandelbrot(int x, int y)
{
    Complex c;
    c.set((x-200)*0.001, y*0.001);
    Complex z;
    z.set(0,0);

    for(int i=0; i<100; i++){
        z = z*z + c;
        if(z.abs() > 2){
            return (COLORREF)(i*167772.15);
        }
    }
    return RGB(0,0,0);
}

COLORREF function_wave(int x, int y)
{
    int r = (int)(255*(cos(20*PAI*y/450)+1)*0.5);
    return RGB(r, r, r);
}

COLORREF function_stripe(int x, int y)
{
    return ((y%30-0.5*30) > 0) ? RGB(0,0,0) : RGB(255,255,255);
}

int main(void)
{
    CRayTraceV5 RayTrace(RGB(128,128,128), 5, 0.1, 0.1, 0.1);

    // Set camera
    RayTrace.SetCamera(vec3d(400, 50, -700),
                       vec3d(100, -40, -150),
                       600, 0,
                       320, 240);

    // Set lights
    RayTrace.SetInfinityLight(vec3d(1, 1, 1), 0.6, 0.6, 0.6);
    RayTrace.SetPointLight(vec3d(600, 600, -300), 0.8, 0.8, 0.8);

    // Place objects
    RayTrace.AddObject(new CObjectBall(vec3d(200, -65, -300), 25,
        RGB(30, 30, 30), 0.75, 0.3, 1.5, 10, 2));
    RayTrace.AddObject(new CObjectBall(vec3d(300, -65, -200), 25,
        RGB(255, 255, 255), 0, 0.4, 1, 3, 0.6));
    RayTrace.AddObject(new CObjectBall(vec3d(30, -65, -190), 25,
        RGB(30, 30, 30), 0.75, 0.3, 1.5, 10, 2));
    RayTrace.AddObject(new CObjectBall(vec3d(185, -65, -170), 25,
        RGB(0, 0, 255), 0, 0.4, 1, 3, 0.8));
    RayTrace.AddObject(new CObjectPlane(vec3d(0, -90, 0), vec3d(0, 1, 0),
        RGB(128, 128, 128), 0, 0.3, 1, 0, 0));

    CBitmap Map1(500, 300);
    CBitmap Map2(900, 450);
    CBitmap Map3(600, 300);
    CBitmap Map4(600, 300);
    Map1.DrawFunctionImage(&function_check);
    Map2.DrawFunctionImage(&function_mandelbrot);
    Map3.DrawFunctionImage(&function_wave);
    Map4.DrawFunctionImage(&function_stripe);

    RayTrace.AddObject(new CObjectMapBall(vec3d(0, 60, 0), 25,
        RGB(255, 255, 255), 0, 0, 1, 3, 0.6,
        &Map1, NULL, NULL));
    RayTrace.AddObject(new CObjectMapBall(vec3d(0, -40, -330), 50,
        RGB(255, 128, 255), 0, 0, 1, 3, 0.6,
        &Map2, NULL, NULL));
    RayTrace.AddObject(new CObjectMapBall(vec3d(210, -65, -130), 25,
        RGB(255, 255, 0), 0, 0.4, 1, 3, 0.8,
        NULL, NULL, &Map3));
    RayTrace.AddObject(new CObjectMapBall(vec3d(130, -65, -170), 25,
        RGB(0, 128, 0), 0, 0.4, 1, 3, 0.8,
        NULL, &Map4, NULL));

    CObjectQuadrics* quad=new CObjectQuadrics(
        vec3d(0, 0, 0),
        6400,25,6400, 1,
        RGB(255, 0, 0), 0, 0.3, 1, 1, 0.65
    );
    quad->BlockPlaneList_Ins(vec3d(0,0,QBLOCK_ZMIN), vec3d(0,0,1));
    quad->BlockPlaneList_Ins(vec3d(0,0,QBLOCK_ZMAX), vec3d(0,0,-1));
    quad->BlockPlaneList_Ins(vec3d(QBLOCK_XMIN,0,0), vec3d(1,0,0));
    quad->BlockPlaneList_Ins(vec3d(QBLOCK_XMAX,0,0), vec3d(-1,0,0));
    RayTrace.AddObject(quad);

    // Execute ray tracing
    CBitmap& image = RayTrace.Start();

    // Save result
    image.SaveBmp("image_QUAD.bmp");

    return 0;
}
