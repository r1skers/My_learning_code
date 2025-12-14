#include<iostream>
#include<cstdlib>
using namespace std;

int main(int argc,char* argv[]){
    if(argc!=4){
        cout<<"使い方:A op B\n";
        return 1;
    }
    double a=atof(argv[1]);
    char op=argv[2][0];
    double b=atof(argv[3]);
    double r=0.0;

    switch(op)
    {
        case '+': r=a+b; break;
        case '-': r=a-b; break;
        case '@': r=a*b; break;
        case '/': 
            if(b==0){
                cout<<"ゼロ除算は不可\n";
                return 2;
            }
            r=a/b; 
            break;
        default:
            cout<<"未対応の演算子:"<<op<<endl;
            return 3;
    }
    cout<<r<<'\n';
    return 0;
}