#include<iostream>
#include"students.h"
using namespace std;

int main(){
    student array[3];
    array[0].set("山田一郎",60,70);
    array[1].set("加藤次郎",50,40);
    array[2].set("高木三郎",80,60);
    for(int i=0;i<3;i++){
        array[i].print();
    }
}