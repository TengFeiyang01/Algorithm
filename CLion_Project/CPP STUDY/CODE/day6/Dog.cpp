//
// Created by ytf on 2023/9/12.
//

#include "Dog.h"
#include <iostream>

Dog::Dog() {
    std::cout << "Dog::Dog()" << std::endl;
}

Dog::~Dog() {
    std::cout << "~Dog::Dog()" << std::endl;
}

void Dog::voice() {
    std::cout << "wang wang wang" << std::endl;
}