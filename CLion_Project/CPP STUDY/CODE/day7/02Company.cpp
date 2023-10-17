#include <bits/stdc++.h>
#include "Technician.h"
#include "Manager.h"
#include "salesman.h"
#include "SaleManager.h"

//牵扯到菱形继承 虚继承

int main() {
/*    Technician tech;
    tech.promote();
    tech.calcSalary();
    tech.disInfor();

    Manager meg;
    meg.promote();
    meg.calcSalary();
    meg.disInfor();

    Salesman sas;
    sas.promote();
    sas.calcSalary();
    sas.disInfor();*/

/*    SaleManager sm;
    sm.init();
    sm.promote();
    sm.calcSalary();
    sm.disInfor();*/

    Employee *empArr[] = {new Manager, new Technician, new Salesman, new SaleManager};

    for (auto &emp : empArr) {
        emp->init();
        if (typeid(*emp) == typeid(Manager)) {
            std::cout << "他提出要涨工资" << std::endl;
            //dynamic_cast 下转
            //此时不为空表明确实可以转换
            if (dynamic_cast<Manager*>(emp)) {
                dynamic_cast<Manager*>(emp)->addSalary(2000);
                std::cout << "jiale\n";
            }
        }

        emp->promote();
        emp->calcSalary();
        emp->disInfor();
    }

/*    std::ranges::for_each(empArr, [](auto emp){
        emp->init();
        emp->promote();
        emp->calcSalary();
        emp->disInfor();
    });*/



    return 0;
}
