#include<iostream>
#include<string>
using namespace std;

class student{
    public:
    string name;
    int eng;
    int math;
    int ave;
    void calc_ave();
    int get_ave();
};

void student::calc_ave(){
    ave = (eng + math) / 2;
}

int student::get_ave(){
    return ave;
}
int main(void)
{
    student yamada={"山田太郎", 60, 80};
    yamada.calc_ave();
    cout<<"average is "<<yamada.get_ave()<<endl;
}