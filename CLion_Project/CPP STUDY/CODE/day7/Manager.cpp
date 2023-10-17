//
// Created by ytf on 2023/9/16.
//

#include "Manager.h"

Manager::Manager() {

}

void Manager::promote() {
    level_ += 4;
}

void Manager::calcSalary() {
    salary_ = fixedSalary_;
}

void Manager::disInfor() {
    std::cout << "姓名         ：" << name_ << std::endl;
    std::cout << "工号         ：" << num_ << std::endl;
    std::cout << "级别         ：" << level_ << std::endl;
    std::cout << "本月的固定薪水：" << fixedSalary_ << std::endl;
    std::cout << "本月的结算薪水：" << salary_ << std::endl;
    std::cout << "====================================" << std::endl;
}

void Manager::init() {
    fixedSalary_ =8000;
    num_ = startNumber_++;
    level_ = 1;
    std::cout << "请输入经理的姓名：" << std::endl;
    std::cin >> name_;
}

Manager::~Manager() {

}

void Manager::addSalary(int val) {
    fixedSalary_ += val;
}
