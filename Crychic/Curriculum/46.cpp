#include<iostream>
using namespace std;
int main(){
    int**p_2d=new int*[3];
    for(int i=0;i<3;i++){
        p_2d[i]=new int[5];
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            p_2d[i][j]=i+j;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            cout<<p_2d[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<3;i++){
        delete[] p_2d[i];
    }
    delete[] p_2d;
    return 0;
}