#include <bits/stdc++.h>

//老师 姓名 性别 年龄 教学 恰饭 dosomething

//学啥 姓名 性别 年龄 学习 恰饭 dosomething

/*class Teacher {
public:
    void teach(std::string course) {
        std::cout << "I am a teacher, teaching " << course << std::endl;
    }

    void eat(std::string food) {
        std::cout << "I am eating " << food << std::endl;
    }
};

class Student {
public:
    void study(std::string course) {
        std::cout << "I am a student, learning " << course << std::endl;
    }

    void eat(std::string food) {
        std::cout << "I am eating " << food << std::endl;
    }
};*/


class Person {
public:
    Person(int age = 0, std::string name = "", std::string sex = "") : age_(age), name_(name), sex_(sex) {}

    void eat(std::string food) {
        std::cout << "I am eating " << food << std::endl;
    }

private:
    int age_;
    std::string name_;
    std::string sex_;
};


//公有继承
class Teacher : public Person {
public:
    void teach(std::string course) {
        std::cout << "I am a teacher, teaching " << course << std::endl;
    }
};

class Student : public Person {
public:
    void study(std::string course) {
        std::cout << "I am a student, learning " << course << std::endl;
    }
};

int main() {

    Teacher t;
    t.teach("C++");
    t.eat("dumplings");

    Student s;
    s.study("C++");
    s.eat("mian");

    return 0;
}
