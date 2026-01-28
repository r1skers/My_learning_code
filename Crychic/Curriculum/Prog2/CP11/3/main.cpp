#include "vec3d.h"
#include <iostream>
#include "camera.h"
#include<iomanip>

using namespace std;

int main(){
    const int imagin_hight_half=320;
    const int imagin_width_half=240;
    const int image_hight=imagin_hight_half*2;
    const int image_width=imagin_width_half*2;

    CCamera camera;
    camera.SetCamera(vec3d(300,160,-600),vec3d(100,-40,-150),600,0,image_width,image_hight);

    int screensize_cx,screensize_cy;
    camera.GetScreenSize(screensize_cx,screensize_cy);

    cout<<fixed<<setprecision(2);

    vec3d viewpoint =camera.GetViewPoint();
    cout<<"viewpoint: "<<viewpoint.x<<" "<<viewpoint.y<<" "<<viewpoint.z<<endl;

    int sx=-screensize_cx;
    int ex=screensize_cx;
    for(int y=0;y<image_hight;y+=100)
    {
        int sy=screensize_cy-y;
        for(int x=sx;x<ex;x+=100)
        {
            vec3d pixelpos=camera.ScreenToAbsolute(x,sy);
            cout<<"("<<x<<","<<sy<<") :"<<pixelpos.x<<" "<<pixelpos.y<<" "<<pixelpos.z<<endl;
        }

    }
    return 0;
}