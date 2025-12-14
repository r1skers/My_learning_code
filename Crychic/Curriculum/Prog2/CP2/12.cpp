#include<iostream>
#include<iomanip>
using namespace std;
void calc_stats(double*s,int n,double*ave,double*var);
int main(){
    double score[10]={50.0,75.0,62.0,65.5,80.0,95.0,90.5,87.0,80.0,99.5};
    double average,variance;
    calc_stats((double*)score,10, &average,&variance);
    cout<<fixed<<setprecision(1);
    cout<<"平均＝"<<average<<",分散="<<variance<<endl;
    return 0;
}
void calc_stats(double*s,int n,double*ave,double*var){
    double sum=0;
    int i;
    for(i=0;i<10;++i){     
        sum+=s[i];
    }
    *ave=sum/n;
    double ave_sum=0.0;
    for(i=0;i<10;++i)
    {
        ave_sum+=((s[i]-*ave)*(s[i]-*ave));
    }
    *var=ave_sum/n;
}