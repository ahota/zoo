#ifndef __ZEBRA_H__
#define __ZEBRA_H__

#include <string>

#include "animal.h"

class Zebra : public Animal
{
    public:
        Zebra();
        void makeSound();
        std::string name;
};

#endif
