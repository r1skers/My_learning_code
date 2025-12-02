#include<stdio.h>
using namespace std;

int main(){
    int cnt=0;
    for(int i=1;i<=1234;i++)
    {
        if(i%2==0)
        {
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}