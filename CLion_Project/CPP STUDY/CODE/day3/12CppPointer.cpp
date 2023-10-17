#include <bits/stdc++.h>

class Student {
public:
    Student(std::string s, int num) : name_(s), num_(num) {}
    void dis(int idx) {
        std::cout << idx << " " << name_ << " " << num_ << std::endl;
    }

private:
    std::string name_;
    int num_;
};

int main() {

    void (Student::*pdis)(int idx) = &Student::dis;

    Student s("zhangsan", 100);
    Student ss("list", 100);
    (s.*pdis)(1);
    (ss.*pdis)(2);

    Student *ps = &s, *pss = &ss;
    (ps->*pdis)(3);
    (pss->*pdis)(4);

    return 0;
}

#if 0
class Student {
public:
    Student(std::string s, int num) : name_(s), num_(num) {}

//private:
    std::string name_;
    int num_;
};

int main() {
    Student s("zhangsan", 100);
    Student ss("list", 200);

    auto ps = &s; //此行为，破坏了封装
    auto pss = &ss;

    //下面讲的指针是指的类层面的指针 而不是对象层面的
    //要想使用，还要根具体的对象产生关系

    std::string Student::*psn = &Student::name_;


//    s.name_ ps->name
    std::cout << s.*psn << std::endl;
    std::cout << ps->*psn << std::endl;

    std::cout << ss.*psn << std::endl;
    std::cout << pss->*psn << std::endl;

    return 0;
}
#endif