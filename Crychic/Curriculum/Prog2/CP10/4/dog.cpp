#include <iostream>
#include "dog.h"

dog::dog(int h):animal_base(h)
{
}

void dog::talk()
{
    std::cout << "bow wow" << std::endl;
}