#include "cat.h"
#include "dog.h"
#include "mouse.h"

int main(void){
    animal_base* animal_A=new cat(30);
    animal_base* animal_B=new dog(80);
    animal_base* animal_C=new mouse(10);

    animal_A->talk();
    animal_B->talk();
    animal_C->talk();

    delete animal_A;
    delete animal_B;
    delete animal_C;
}