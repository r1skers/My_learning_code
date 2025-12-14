#include<iostream>
using namespace std;
int main(){
    int score[10]={85,90,75,30,58,62,100,98,70,48};
    int total=0;
    double average;
    for(int i=0;i<10;++i)
    {
        total+=score[i];
    }
    average=static_cast<double>(total)/10.0;
    cout<<"average="<<average<<endl;

    return 0;
}