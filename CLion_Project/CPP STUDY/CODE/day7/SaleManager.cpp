//
// Created by ytf on 2023/9/16.
//

#include "SaleManager.h"

SaleManager::SaleManager() {

}

void SaleManager::promote() {
    level_ += 3;
}

void SaleManager::calcSalary() {
    salary_ = fixedSalary_ + saleAmount_ * rate_;
}

void SaleManager::disInfor() {
    std::cout << "姓名         ：" << name_ << std::endl;
    std::cout << "工号         ：" << num_ << std::endl;
    std::cout << "级别         ：" << level_ << std::endl;
    std::cout << "本月的固定薪水：" << fixedSalary_ << std::endl;
    std::cout << "本月的提成比率：" << rate_ << std::endl;
    std::cout << "本月的结算薪水：" << salary_ << std::endl;
    std::cout << "====================================" << std::endl;
}

void SaleManager::init() {
    fixedSalary_ = 5000;
    level_ = 1;
    num_ = startNumber_++;
    rate_ = 0.05;
    std::cout << "请输入销售经理姓名：" << std::endl;
    std::cin >> name_;
    std::cout << "请输入本月销售额：" << std::endl;
    std::cin >> saleAmount_;
}

SaleManager::~SaleManager() {

}
