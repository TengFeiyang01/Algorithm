//
// Created by ytf on 2023/9/20.
//

#include "C.h"
#include "conf.h"
#include <iostream>


C::C() {
    conf * cf = conf::getInstance();
    std::cout << cf->getIP() << " " << cf->getPort() << std::endl;
}
