#include <iostream>

#include "cat.h"

Cat::Cat()
    : name("cat")
{
}

void Cat::makeSound()
{
    std::cout << "meow" << std::endl;
}

extern "C" Cat *createCat()
{
    return new Cat;
}

extern "C" void destroyCat(Cat *c)
{
    delete c;
}
