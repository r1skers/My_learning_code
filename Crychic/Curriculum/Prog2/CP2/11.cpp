#include<iostream>
using namespace std;
int permutation(int n,int r);
int main(){
    int n=5,r=3;
    cout<<n<<"p"<<r<<"="<<permutation(n,r)<<endl;
    return 0;
}
int permutation(int n,int r){
    if(r!=0){
        return n*permutation(n-1,r-1);
    }
    else
    {
        return 1;
    }
}