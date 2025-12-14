#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream ifs("binary.bin",ios::binary);
    if(!ifs){
        cerr<<"Error opening file for reading"<<endl;
        return 1;
    }

    char bytes[9];
    ifs.read(bytes, sizeof(char));

    int ints[9];
    ifs.read((char*)ints, 9*sizeof(ints));

    cout<<"read bytes[9]"<<endl;
    for(int i=0;i<9;++i){
        cout<<"bytes["<<i<<"]:"<<(int)bytes[i]<<endl;
    }

    cout<<"read ints[9]"<<endl;
    for(int i=0;i<9;++i){
        cout<<"ints["<<i<<"]:"<<ints[i]<<endl;
    }
    return 0;
}