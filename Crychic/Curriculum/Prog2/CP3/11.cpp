#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    vector<string> name={"a","b","c","d","e","f","g","h","i","j"};
    vector<int> price={120,80,200,150,90,130,220,60,300,110};
    vector<int> taste={6,3,9,7,4,6,10,2,12,5};
    int B=500;
    int n=(int)price.size();
    int BestBit=0;
    int BestTaste=-1;
    int BestCost=0;
    for(int bit=0;bit<(1<<n);++bit)
    {
        vector<int>S;
        for(int i=0;i<n;++i)
        {
            if(bit&(1<<i)) S.push_back(i);
        }
        int cost=0,val=0;
        bool over=false;
        for(int idx: S){
            cost+=price[idx];
            val+=taste[idx];
            if(cost>B){over=true;break;}
        }
        if(over)continue;
        if(val>BestTaste||(val==BestTaste&&cost<BestCost))
        {
            BestTaste=val;
            BestCost=cost;
            BestBit=bit;
        }
    }
    cout<<"予算:"<<B<<endl;
    cout<<"満足度:"<<BestTaste<<endl;
    
    cout<<"合計価格:"<<BestCost<<endl;
    cout<<"選んだ品物:{";
    bool first=true;
    for(int i=0;i<n;++i)
    {
        if(BestBit&(1<<i))
        {
            if(!first)cout<<",";
            first=false;
            cout<<name[i];
        }
    }
    cout<<"}"<<endl;
    return 0;
}   