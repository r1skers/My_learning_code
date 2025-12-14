#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

struct Vector3d{
    double x,y,z;
};

void WriteVector3d(const Vector3d vec,string filename){
    ofstream ofs(filename, ios::binary);
    ofs.write((char*)&vec.x, sizeof(vec.x));
    ofs.write((char*)&vec.y, sizeof(vec.y));
    ofs.write((char*)&vec.z, sizeof(vec.z));
}

void ReadVector3d(Vector3d &vec, string filename){
    ifstream ifs(filename, ios::binary);
    ifs.read((char*)&vec.x, sizeof(vec.x));
    ifs.read((char*)&vec.y, sizeof(vec.y));
    ifs.read((char*)&vec.z, sizeof(vec.z));
    ifs.close();
}

int main(){
    Vector3d vec1={1.0,2.0,3.0};
    WriteVector3d(vec1,"vec.bin");

    Vector3d vec2;
    ReadVector3d(vec2,"vec.bin");
    cout<<"Read Vector3d: ("<<vec2.x<<","<<vec2.y<<","<<vec2.z<<")"<<endl;
    return 0;
}