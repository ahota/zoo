#ifndef __CAT_H__
#define __CAT_H__

#include <string>

#include "animal.h"

class Cat : public Animal
{
    public:
        Cat();
        void makeSound();
        std::string name;
};

#endif
