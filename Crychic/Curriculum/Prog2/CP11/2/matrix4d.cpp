#include "matrix4d.h"
#include <cmath>
#include <algorithm>

matrix4d::matrix4d()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            data[i][j]=0.0;
}

matrix4d matrix4d::Identity(){
    matrix4d res;
    for(int i=0;i<4;i++)
        res.data[i][i]=1.0;
    return res;
}

matrix4d matrix4d::operator +(const matrix4d& op) const{
    matrix4d res;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            res.data[i][j]=data[i][j]+op.data[i][j];
    return res;
}

matrix4d matrix4d::operator -(const matrix4d& op) const{
    matrix4d res;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            res.data[i][j]=data[i][j]-op.data[i][j];
    return res;
}

matrix4d matrix4d::operator *(const matrix4d& op) const{
    matrix4d res;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
                res.data[i][j]+=data[i][k]*op.data[k][j];
    return res;
}

bool matrix4d::SolveGaussJordan(const double b[4], double x_out[4]) const{
    double a[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            a[i][j]=data[i][j];
        x_out[i]=b[i];
    }
        

    for(int k=0;k<4;k++){
        int pivot=k;
        for(int j=k+1;j<4;j++){
            if(std::fabs(a[j][k])>std::fabs(a[pivot][k])){
                pivot=j;
            }
        }
        for(int j=0;j<4;j++){
            std::swap(a[k][j],a[pivot][j]);
        }
        std::swap(x_out[k],x_out[pivot]);

        if(std::fabs(a[k][k])<1e-12){
            return false;
        }

        double a_kk_prev=a[k][k];
        for(int j=k+1;j<4;j++){
            a[k][j]/=a_kk_prev;
        }
        x_out[k]/=a_kk_prev;
        a[k][k]=1.0;

        for(int i=0;i<4;i++){
            if(i!=k){
                double a_ik_prev=a[i][k];
                for(int j=k+1;j<4;j++){
                    a[i][j]-=a_ik_prev*a[k][j];
                }
                x_out[i]-=a_ik_prev*x_out[k];
                a[i][k]=0.0;
            }
        }
    }
    return true;
}

matrix4d matrix4d::Inverse() const{
    matrix4d res=matrix4d::Identity();
    double a[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            a[i][j]=data[i][j];
    }
    for(int k=0;k<4;k++){
        int pivot=k;
        for(int j=k+1;j<4;j++){
            if(std::fabs(a[j][k])>std::fabs(a[pivot][k])){
                pivot=j;
            }
        }
        for(int j=0;j<4;j++){
            std::swap(a[k][j],a[pivot][j]);
            std::swap(res.data[k][j],res.data[pivot][j]);
        }
        if(std::fabs(a[k][k])<1e-12){
            return matrix4d::Identity();
        }
        double a_kk_prev=a[k][k];
        for(int j=0;j<4;j++){
            a[k][j]/=a_kk_prev;
            res.data[k][j]/=a_kk_prev;
        }
        a[k][k]=1.0;

        for(int i=0;i<4;i++){
            if(i!=k){
                double a_ik_prev=a[i][k];
                for(int j=0;j<4;j++){
                    a[i][j]-=a_ik_prev*a[k][j];
                    res.data[i][j]-=a_ik_prev*res.data[k][j];
                }
                a[i][k]=0.0;
            }
        }
    }
    return res;
}