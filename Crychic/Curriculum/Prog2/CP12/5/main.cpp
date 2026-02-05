#include "vec3d.h"
#include "bitmap.h"
#include "object_ball.h"
#include "raytrace.h"
#include "object_plane.h"
#include "raytrace_v2.h"
#include "raytrace_v3.h"
#include "raytrace_v4.h"

int main(void)
{
    CRayTraceV4 RayTrace(RGB(128, 128, 128), 5, 0.1, 0.1, 0.1);
    // Set camera
    RayTrace.SetCamera(vec3d(400, 50, -700),
                       vec3d(100, -40, -150),
                       600, 0,
                       320, 240);
    // Place objects
    RayTrace.SetInfinityLight(vec3d(1, 1, 1), 0.6, 0.6, 0.6);
    RayTrace.SetPointLight(vec3d(600, 600, -300), 0.8, 0.8, 0.8);
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
    // Execute ray tracing
    CBitmap& image = RayTrace.Start();
    // Save result
    image.SaveBmp("image_V4.bmp");
    return 0;
}