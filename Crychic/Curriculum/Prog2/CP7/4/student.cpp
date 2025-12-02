#include"student.h"

void student::calc_ave(){
    ave = (eng + math) / 2;
}

int student::get_ave(){
    return ave;
}
