#ifndef MATRIX4D_H
#define MATRIX4D_H

#include "vec3d.h"
class matrix4d{
    public:
        double data[4][4];

        matrix4d();
        static matrix4d Identity();

        matrix4d operator+(const matrix4d& op) const;
        matrix4d operator-(const matrix4d& op) const;
        matrix4d operator*(const matrix4d& op) const;
        vec3d operator*(const vec3d& v) const;

        bool SolveGaussJordan(const double b[4], double x_out[4]) const;
        matrix4d Inverse() const;
};

#endif