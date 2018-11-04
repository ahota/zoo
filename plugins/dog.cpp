#include <iostream>

#include "dog.h"

Dog::Dog()
    : name("dog")
{
}

void Dog::makeSound()
{
    std::cout << "bark" << std::endl;
}

extern "C" Dog *createDog()
{
    return new Dog;
}

extern "C" void destroyDog(Dog *d)
{
    delete d;
}
