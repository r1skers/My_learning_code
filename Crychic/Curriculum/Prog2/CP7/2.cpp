#include<iostream>
#include<string>
using namespace std;

class student{
    public:
    string name;
    int eng;
    int math;
    int ave;
    void calc_ave(student* x){
    x->ave = (x->eng + x->math) / 2;
    }
    int get_ave(const student& x){
    return x.ave;
    }
};




int main(void)
{
    student yamada={"山田太郎", 60, 80};
    yamada.calc_ave(&yamada);
    cout<<"average is "<<yamada.get_ave(yamada)<<endl;
}