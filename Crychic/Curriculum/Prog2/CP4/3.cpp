#include<iostream>
#include<cstdio>
#include<cctype>
using namespace std;

int main(int argc,char* argv[]){
    if(argc<3){
        cout<<"使い方:"<<endl;
        return 1;
    }
    if(argv[1][1]!='\0'){
        std::printf("エラー");
        return 2;
    }
    unsigned char target=argv[1][0];

    int count=0;
    for(int i=2;i<argc;i++){
        const unsigned char* p=(unsigned char*)argv[i];
        while(*p){
            if(*p==target){
                count++;
            }
            p++;
        }
    }
    cout<<count<<endl;
    return 0;
}