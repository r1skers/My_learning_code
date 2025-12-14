#include<iostream>
using namespace std;
const unsigned int OX=1<<0;
const unsigned int OW=1<<1;
const unsigned int OR=1<<2;
const unsigned int GX=1<<3;
const unsigned int GW=1<<4;
const unsigned int GR=1<<5;
const unsigned int UX=1<<6;
const unsigned int UW=1<<7;
const unsigned int UR=1<<8;

void to_perm_chars(unsigned int mode,char out[10]){
    out[0]=(mode&UR)?'r':'-';
    out[1]=(mode&UW)?'w':'-';
    out[2]=(mode&UX)?'x':'-';
    out[3]=(mode&GR)?'r':'-';
    out[4]=(mode&GW)?'w':'-';
    out[5]=(mode&GX)?'x':'-';
    out[6]=(mode&OR)?'r':'-';
    out[7]=(mode&OW)?'w':'-';
    out[8]=(mode&OX)?'x':'-';
    out[9]='\0';
}

int main(){
    unsigned int mode=0;
    mode |=(UR | UW | UX);
    mode |=(GR | GX);
    mode |=(OR | OX);
    mode |=(GW);
    char out[10];
    to_perm_chars(mode,out);
    cout<<out<<endl;
}