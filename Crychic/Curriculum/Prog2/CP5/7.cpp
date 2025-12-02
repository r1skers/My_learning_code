#include<iostream>
using namespace std;
int** alloc2d(int n,int m){
    int **a=new int *[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int [m];
    }
    return a;
}

void free2d(int**a,int n)
{
    for(int i=0;i<n;i++)
    {
        delete [] a[i];
    }
    delete [] a;
}

void matmul(int n,int **A, int **B, int **C)
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            int s=0;
            for(int k=0;k<n;++k)
            {
                s+=A[i][k]*B[k][j];
            }
            C[i][j]=s;
        }
    }
}

void print(int**a,int n,int m)
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main(){
    int n=3;
    int **A=alloc2d(n,n);
    int **B=alloc2d(n,n);
    int **C=alloc2d(n,n);

    int v=1;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            A[i][j]=v++;
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            B[i][j]=v--;
        }
    }
    matmul(n,A,B,C);
    cout<<"A"<<endl;
    print(A,n,n);
    cout<<"B"<<endl;
    print(B,n,n);
    cout<<"C"<<endl;
    print(C,n,n);

    free2d(A,n);
    free2d(B,n);
    free2d(C,n);
}