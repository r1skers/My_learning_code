#include "vec3d.h"
#include <cmath>

vec3d::vec3d(double ax,double ay,double az)
{
    x=ax;
    y=ay;
    z=az;
}

vec3d::vec3d()
{
    x=0;
    y=0;
    z=0;
}

vec3d::vec3d(const vec3d& other) = default;

vec3d::~vec3d()
{
}

bool vec3d::operator ==(const vec3d& op) const
{
    return (x==op.x)&&(y==op.y)&&(z==op.z);
}

bool vec3d::operator !=(const vec3d& op) const
{
    return (x!=op.x)||(y!=op.y)||(z!=op.z);
}

vec3d vec3d::operator +(const vec3d& op) const
{
    return vec3d(x+op.x,y+op.y,z+op.z);
}

void vec3d::operator +=(const vec3d& op)
{
    x+=op.x;
    y+=op.y;
    z+=op.z;
}

vec3d vec3d::operator -(const vec3d& op) const
{
    return vec3d(x-op.x,y-op.y,z-op.z);
}

void vec3d::operator -=(const vec3d& op)
{
    x-=op.x;
    y-=op.y;
    z-=op.z;
}

vec3d vec3d::operator -() const
{
    return vec3d(-x,-y,-z);
}

vec3d vec3d::operator *(double k) const
{
    return vec3d(x*k,y*k,z*k);
}

void vec3d::operator *=(double k)
{
    x*=k;
    y*=k;
    z*=k;
}

vec3d vec3d::operator /(double k) const
{
    return vec3d(x/k,y/k,z/k);
}

void vec3d::operator /=(double k)
{
    x/=k;
    y/=k;
    z/=k;
}

vec3d& vec3d::operator =(const vec3d& op)
{
    x=op.x;
    y=op.y;
    z=op.z;
    return *this;
}

double& vec3d::operator [](int i)
{
    if(i==0) return x;
    if(i==1) return y;
    return z;
}

void vec3d::UnitVec()
{
    double l=Length();
    if(l==0)
    {
        x=y=z=0;
    }
    else
    {
        x/=l;
        y/=l;
        z/=l;
    }
}

void vec3d::InverseVec()
{
    x=-x;
    y=-y;
    z=-z;
}

double vec3d::Length() const
{
    return sqrt(x*x+y*y+z*z);
}

double vec3d::InnerProduct(const vec3d& op) const
{
    return x*op.x+y*op.y+z*op.z;
}

vec3d vec3d::OuterProduct(const vec3d& op) const
{
    return vec3d(y*op.z-z*op.y,
                 z*op.x-x*op.z,
                 x*op.y-y*op.x);
}
