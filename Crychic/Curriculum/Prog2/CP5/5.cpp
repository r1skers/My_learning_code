#include<iostream>
using namespace std;
int& min_ref(int& a, int& b){
    return (b<a)?b:a;
}
int main(){
    int x=2,y=3;
    min_ref(x,y)=0;
    cout<<x<<" "<<y<<endl;
}