#include<iostream>
using namespace std;
int main(){
    int* array=new int[7];
    for(int i=0;i<7;i++){
        array[i]=i;
    }
    for(int i=0;i<7;i++){
        cout<<array[i]<<endl;
    }
    delete[] array;
}