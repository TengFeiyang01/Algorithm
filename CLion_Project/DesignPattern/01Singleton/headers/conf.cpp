//
// Created by ytf on 2023/9/20.
//

#include "conf.h"
#include <fstream>
#include <iostream>

conf * conf::ins = nullptr;


conf* conf::getInstance() {
    if (ins == nullptr) {
        ins = new conf;
    }
    return ins;
}

conf::conf() {
    std::fstream fs;
    fs.open(R"(E:\0CODE\CLion_Project\DesignPattern\01Singleton\headers\com.cof)", std::ios::in | std::ios::out);
    if (!fs) {
        std::cout << "ERROR!!!" << std::endl;
    }
    fs >> IP.ip;
    fs >> IP.port;
    fs.close();
}