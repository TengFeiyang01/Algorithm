//
// Created by ytf on 2023/9/16.
//

#include "salesman.h"

Salesman::Salesman() {

}

void Salesman::promote() {
    level_ += 1;
}

void Salesman::calcSalary() {
    salary_ = saleAmount_ * rate_;
}

void Salesman::disInfor() {
    std::cout << "姓名         ：" << name_ << std::endl;
    std::cout << "工号         ：" << num_ << std::endl;
    std::cout << "级别         ：" << level_ << std::endl;
    std::cout << "本月的提成比率：" << rate_ << std::endl;
    std::cout << "本月的结算薪水：" << salary_ << std::endl;
    std::cout << "====================================" << std::endl;
}

void Salesman::init() {
    rate_ = 0.04;
    num_ = startNumber_++;
    level_ = 1;
    std::cout << "请输入销售员姓名：" << std::endl;
    std::cin >> name_;
    std::cout << "请输入本月销售额：" << std::endl;
    std::cin >> saleAmount_;
}

Salesman::~Salesman() {

}
