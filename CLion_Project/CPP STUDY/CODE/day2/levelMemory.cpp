#include <bits/stdc++.h>

//内存管理层次分明, 只对本层的内存负责

class Birthday {
public:
    Birthday() {
        std::cout << "Birthday()" << std::endl;
        year = new int(1999);
        month = new int(9);
        day = new int(9);
    }

    ~Birthday() {
        std::cout << "~Birthday()" << std::endl;
        delete year;
        delete month;
        delete day;
    }

private:
    int *year, *month, *day;
};

class Stu {
public:
    Stu() {
        std::cout << "Stu()" << std::endl;
        name = new char [1024];
        bir = new Birthday;
    }

    Stu(int _age, char *_name) {
        std::cout << "Stu(int _age, char *_name)" << std::endl;
        name = new char [1024];
        strcpy(name, _name);
        age = _age;
    }

    ~Stu() {
        std::cout << "~Stu() " << std::endl;
        delete []name;
        delete bir;
    }

private:
    char *name;
    int age{};
    Birthday *bir;
};

int main() {
//    C语言
//    Stu *ps = new Stu;
//    ps->name = new char [1024];
//    strcpy(ps->name, "xiaoming");
//    ps->age = 19;
//
//    delete []ps->name; //不加这一行 导致内存泄漏
//    delete ps;

    Stu *ps = new Stu();
    delete ps;

    return 0;
}
