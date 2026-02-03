#include "vec3d.h"
#include "bitmap.h"
#include "object_ball.h"
#include "raytrace.h"
int main(void)
{
    CRayTrace RayTrace(RGB(128, 128, 128), 5, 2.0, 2.0, 2.0);
    // Set camera
    RayTrace.SetCamera(vec3d(400, 50, -700),
                       vec3d(100, -40, -150),
                       600, 0,
                       320, 240);
    // Place objects
    RayTrace.AddObject(new CObjectBall(vec3d(200, -65, -300), 25,
        RGB(30, 30, 30), 0.75, 0.3, 1.5, 10, 2));
    RayTrace.AddObject(new CObjectBall(vec3d(300, -65, -200), 25,
        RGB(255, 255, 255), 0, 0.4, 1, 3, 0.6));
    RayTrace.AddObject(new CObjectBall(vec3d(30, -65, -190), 25,
        RGB(30, 30, 30), 0.75, 0.3, 1.5, 10, 2));
    RayTrace.AddObject(new CObjectBall(vec3d(185, -65, -170), 25,
        RGB(0, 0, 255), 0, 0.4, 1, 3, 0.8));
    // Execute ray tracing
    CBitmap& image = RayTrace.Start();
    // Save result
    image.SaveBmp("image_V1.bmp");
    return 0;
}
