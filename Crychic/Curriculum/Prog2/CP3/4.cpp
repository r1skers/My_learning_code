#include<iostream>
using namespace std;
int main(){
    for(int x=1;x<=100000;x++){
        if((x>0)&&((x&(x-1)))==0){
            cout<<x<<"is a power of 2"<<endl;
        }
    }
}
    