#include<iostream>
using namespace std;
int main(){
    double square[4][2]={{0.0,0.0},{20.0,0.0},{20.0,10.0},{10.0,0.0}};
    double move_x,move_y;
    cout<<"Input value of move_x."<<endl;
    cin>>move_x;
    cout<<"Input value of move_y."<<endl;
    cin>>move_y;
    for(int i=0;i<4;++i)
    {
        double to_x=square[i][0]+move_x;
        double to_y=square[i][1]+move_y;
        cout<<"("<<to_x<<","<<to_y<<")"<<endl;
   }
    return 0;
}