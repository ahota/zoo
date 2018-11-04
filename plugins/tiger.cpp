#include <iostream>

#include "tiger.h"

Tiger::Tiger()
    : name("tiger")
{
}

void Tiger::makeSound()
{
    std::cout << "roar" << std::endl;
}

extern "C" Tiger *createTiger()
{
    return new Tiger;
}

extern "C" void destroyTiger(Tiger *c)
{
    delete c;
}
