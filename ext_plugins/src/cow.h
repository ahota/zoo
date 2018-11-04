#ifndef __COW_H__
#define __COW_H__

#include <string>

#include "animal.h"

class Cow : public Animal
{
    public:
        Cow();
        void makeSound();
        std::string name;
};

#endif
