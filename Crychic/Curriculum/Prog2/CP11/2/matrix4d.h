#ifndef MATRIX4D_H
#define MATRIX4D_H

class matrix4d{
    public:
        double data[4][4];

        matrix4d();
        static matrix4d Identity();

        matrix4d operator +(const matrix4d& op) const;
        matrix4d operator -(const matrix4d& op) const;

        matrix4d operator *(const matrix4d& op) const;

        bool SolveGaussJordan(const double b[4], double x_out[4]) const;
        matrix4d Inverse() const;
};

#endif