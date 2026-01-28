#include <iostream>
#include "matrix4d.h"
#include <iomanip>
#include "vec3d.h"

using namespace std;

void PrintMatrix(const matrix4d& m,const string& name){
    cout<<"---"<<name<<"---"<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<setw(10)<<fixed<<setprecision(4)<<m.data[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    matrix4d A = matrix4d::Identity();
    matrix4d B = matrix4d::Identity();

    B.data[0][0] = 2.0;
    B.data[1][1] = 2.0;

    matrix4d Sum = A + B;
    matrix4d Diff = B - A;

    PrintMatrix(Sum, "Matrix A + B");
    PrintMatrix(Diff, "Matrix B - A");

    matrix4d M1 =matrix4d::Identity();
    M1.data[0][3]=10.0;
    matrix4d M2 =matrix4d::Identity();
    M2.data[0][0]=0.0;M2.data[0][1]=-1.0;M2.data[1][0]=1.0;M2.data[1][1]=0.0;

    matrix4d M_combined = M1 * M2;
    PrintMatrix(M_combined, "Combined Matrix (M1 * M2)");

    matrix4d Eq;
    Eq.data[0][0]=2;Eq.data[0][1]=1;Eq.data[0][2]=1;
    Eq.data[1][0]=1;Eq.data[1][1]=2;Eq.data[1][2]=1;
    Eq.data[2][0]=1;Eq.data[2][1]=1;Eq.data[2][2]=2;
    Eq.data[3][3]=1;

    double b[4]={1.0,2.0,5.0,1.0};
    double x_out[4];

    PrintMatrix(Eq, "Equation Matrix (4x4)");
    if (Eq.SolveGaussJordan(b, x_out)) {
        cout << "Solve Ax=b" << endl;
        cout<<"x= "<<x_out[0]<<",y= "<<x_out[1]<<",z= "<<x_out[2]<<endl;
        cout<<"Expected: x=-1,y=0,z=3"<<endl;
    }
    else {
        cout << "Failed to solve." << endl;
    }
    cout<<endl;

    matrix4d Eq_inv = Eq.Inverse();
    PrintMatrix(Eq_inv, "Equation Matrix Inverse");

    matrix4d IdentityCheck = Eq * Eq_inv;
    PrintMatrix(IdentityCheck, "Check: Eq * Eq_inv (Should be Identity)");

    return 0;
}