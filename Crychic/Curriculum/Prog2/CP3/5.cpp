#include<iostream>
#include<bitset>
using namespace std;
int main(){
    int x;
    cin>>x;
    int count=0;
    for(int i=x;i;i&=i-1){
        cout<<bitset<8>(i)<<endl;
        count++;
    }
    cout<<"Number of 1 bits:"<<count<<endl;
}