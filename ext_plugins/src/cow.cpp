#include <iostream>

#include "cow.h"

Cow::Cow()
    : name("cow")
{
}

void Cow::makeSound()
{
    std::cout << "moo" << std::endl;
}

extern "C" Cow *createCow()
{
    return new Cow;
}

extern "C" void destroyCow(Cow *c)
{
    delete c;
}
