#include <iostream>
#include "cat.h"

cat::cat(int h):animal_base(h)
{
}

void cat::talk()
{
    std::cout << "meow" << std::endl;
}