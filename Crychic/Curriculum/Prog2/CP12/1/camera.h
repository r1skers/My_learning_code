#ifndef CAMERA_H
#define CAMERA_H

#include "vec3d.h"
#include "matrix4d.h"

class CCamera
{
    public:
        vec3d ScreenToAbsolute(int x,int y);

        void SetCamera(vec3d pos,vec3d target,double angle,double turnangle,int screen_cx,int screen_cy);

        vec3d GetViewPoint(){return viewpoint;}
        vec3d GetDirection(){return direction;}
        double GetAngle(){return angle;}
        double GetTurnAngle(){return turnangle;}
        void GetScreenSize(int &sx,int &sy){sx=screen_cx;sy=screen_cy;}

    private:
        vec3d viewpoint;
        vec3d direction;
        double angle;
        double turnangle;
        int screen_cx;
        int screen_cy;
        matrix4d V;
        void CalculationV();
};

#endif