#include "camera.h"
#include <math.h>

void CCamera::SetCamera(vec3d pos,vec3d target,double a,double ta,int screen_cx,int screen_cy)
{
    viewpoint=pos;
    direction=target-pos;
    direction.UnitVec();
    this->angle=angle;
    this->turnangle=turnangle;
    this->screen_cx=screen_cx;
    this->screen_cy=screen_cy;
    CalculationV();
}

void CCamera::CalculationV()
{
    double xz_len=sqrt(direction.x*direction.x+direction.z*direction.z);
    double sina=direction.x/xz_len;
    double cosa=direction.z/xz_len;
    double sinb=direction.y;
    double cosb=xz_len;

    double sinr=sin(turnangle);
    double cosr=cos(turnangle);

    matrix4d mRx=matrix4d::Identity();
    matrix4d mRy=matrix4d::Identity();
    matrix4d mRz=matrix4d::Identity();
    matrix4d mT=matrix4d::Identity();

    mRx.data[1][1]=cosb;
    mRx.data[1][2]=sinb;
    mRx.data[2][1]=-sinb;
    mRx.data[2][2]=cosb;

    mRy.data[0][0]=cosa;
    mRy.data[0][2]=sina;
    mRy.data[2][0]=-sina;
    mRy.data[2][2]=cosa;

    mRz.data[0][0]=cosr;
    mRz.data[0][1]=sinr;
    mRz.data[1][0]=-sinr;
    mRz.data[1][1]=cosr;

    vec3d origin =viewpoint + direction * angle;
    mT.data[0][3]=origin.x;
    mT.data[1][3]=origin.y;
    mT.data[2][3]=origin.z;

    this->V=mT*mRz*mRy*mRx;
}

vec3d CCamera::ScreenToAbsolute(int x,int y)
{
    return V * vec3d((double)x,(double)y,0.0);
}