#ifndef __TIGER_H__
#define __TIGER_H__

#include <string>

#include "animal.h"

class Tiger : public Animal
{
    public:
        Tiger();
        void makeSound();
        std::string name;
};

#endif
