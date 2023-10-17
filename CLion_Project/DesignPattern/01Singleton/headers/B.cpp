//
// Created by ytf on 2023/9/20.
//

#include "B.h"
#include "conf.h"
#include <iostream>

B::B() {
    conf * cf = conf::getInstance();
    std::cout << cf->getIP() << " " << cf->getPort() << std::endl;
}