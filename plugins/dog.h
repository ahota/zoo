#ifndef __DOG_H__
#define __DOG_H__

#include <string>

#include "animal.h"

class Dog : public Animal
{
    public:
        Dog();
        void makeSound();
        std::string name;
};

#endif
