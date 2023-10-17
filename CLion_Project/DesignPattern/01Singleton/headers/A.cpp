//
// Created by ytf on 2023/9/20.
//

#include "A.h"
#include "conf.h"
#include <iostream>

A::A() {
    conf * cf = conf::getInstance();
    std::cout << cf->getIP() << " " << cf->getPort() << std::endl;
}
