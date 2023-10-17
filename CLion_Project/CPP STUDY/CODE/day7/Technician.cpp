#include "Technician.h"

Technician::Technician() {

}

void Technician::promote() {
    level_ += 3;
}

void Technician::disInfor() {
    std::cout << "姓名         ：" << name_ << std::endl;
    std::cout << "工号         ：" << num_ << std::endl;
    std::cout << "级别         ：" << level_ << std::endl;
    std::cout << "本月工作的小时数：" << amountHour_ << std::endl;
    std::cout << "每个工作时的薪水：" << moneyPerHour_ << std::endl;
    std::cout << "本月的结算薪水：" << salary_ << std::endl;
    std::cout << "====================================" << std::endl;
}

void Technician::calcSalary() {
    salary_ = moneyPerHour_ * amountHour_;
}

void Technician::init() {
    std::cout << "请输入技术人员的姓名：" << std::endl;
    std::cin >> name_;
    num_ = startNumber_++;
    level_ = 1;
    moneyPerHour_ = 100;
    std::cout << "请输入本月工作小时数："<< std::endl;
    std::cin >> amountHour_;
}

Technician::~Technician() {

}

