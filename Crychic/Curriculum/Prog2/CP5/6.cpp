#include<iostream>
using namespace std;
int my_strlen(const char* s){
    const char* p=s;
    while(*p!=' ')++p;
    return p-s;
}
int main(){
    cout<<my_strlen("hello world!!")<<endl;//5
}