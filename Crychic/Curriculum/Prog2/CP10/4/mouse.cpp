#include <iostream>
#include "mouse.h"

mouse::mouse(int h):animal_base(h)
{
}

void mouse::talk()
{
    std::cout << "squeak" << std::endl;
}