#ifndef VEC3D_H
#define VEC3D_H

class vec3d
{
    public:
        double x;
        double y;
        double z;

        vec3d(double ax,double ay,double az);
        vec3d();
        vec3d(const vec3d& other);
        ~vec3d();
        void UnitVec();
        void InverseVec();
        double Length() const;
        double InnerProduct(const vec3d& op) const;
        vec3d OuterProduct(const vec3d& op) const;

    public:
        bool operator ==(const vec3d& op) const;
        bool operator !=(const vec3d& op) const;

        vec3d operator +(const vec3d& op) const;
        void operator +=(const vec3d& op) ;

        vec3d operator -(const vec3d& op) const;
        void operator -=(const vec3d& op) ;

        vec3d operator -() const;

        vec3d operator *(double k) const;
        void operator *=(double k) ;
        vec3d operator /(double k) const;
        void operator /=(double k) ;

        vec3d& operator =(const vec3d& op) ;

        double& operator [](int i) ;
};

#endif
