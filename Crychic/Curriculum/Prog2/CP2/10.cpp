#include<iostream>
using namespace std;
void get_ave(double* score,double* ave);
int main(){
    double result[5][3]={{50,65,45},{77,80,90},{30,40,50},{75,92,80},{65,69,90}};
    double average[3];
    get_ave((double*)result,average);
    cout<<"Average is "<<average[0]<<"(Eng),"<<average[1]<<"(Math),"<<average[2]<<"(Jpan)\n";

}
void get_ave(double* score,double* ave){
    int i,j;
    double total[3];
    for(i=0;i<3;++i)
    {
        total[i]=0.0;
        for(j=0;j<5;++j){
            total[i]+=*(score+3*j+i);
        }   
    }
     for(i=0;i<3;++i)
        {
            *(ave+i)=total[i]/5.0;
        }
}