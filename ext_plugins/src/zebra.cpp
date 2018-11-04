#include <iostream>

#include "zebra.h"

Zebra::Zebra()
    : name("zebra")
{
}

void Zebra::makeSound()
{
    std::cout << "bray" << std::endl;
}

extern "C" Zebra *createZebra()
{
    return new Zebra;
}

extern "C" void destroyZebra(Zebra *z)
{
    delete z;
}
