#include<iostream>
using namespace std;

int main(int argc,char *argv[])
{
    cout<<"コマンドライン引数の個数:"<<argc<<endl;
    for(int i=0;i<argc;i++)
    {
        cout<<"引数"<<i<<":"<<argv[i]<<endl;
    }
    return 0;
}