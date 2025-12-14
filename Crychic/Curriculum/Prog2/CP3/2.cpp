#include<iostream>
#include<bitset>
using namespace std;
int main()
{
    char x='a';
    char encode=x^0xFF;
    char decode=encode^0xFF;
    cout<<"元の値"<<x<<"("<<bitset<8>(x)<<")"<<endl;
    cout<<"エンコード後"<<encode<<"("<<bitset<8>(encode)<<")"<<endl;
    cout<<"デコード後"<<decode<<"("<<bitset<8>(decode)<<")"<<endl;
}