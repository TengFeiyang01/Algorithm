//
// Created by ytf on 2023/9/12.
//

#include "Cat.h"
#include <iostream>

Cat::Cat() {
    std::cout << "Cat::Cat()" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat::Cat()" << std::endl;
}

void Cat::voice() {
    std::cout << "miao miao miao" << std::endl;
}
