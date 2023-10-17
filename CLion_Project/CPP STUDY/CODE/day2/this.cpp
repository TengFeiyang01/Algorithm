#include <bits/stdc++.h>

//this指针指向当前对象的指针,在哪里可以用, 以什么样的形式使用，这样用有什么好处
//this指针作为函数参数隐式传进来, 不占用对象的体积大小
//避免了形参与数据成员重名
//可以实现链式表达，a = b = c

class Stu {
public:
    Stu(std::string name = "None", int age = 0) {
        this->name = name;
        this->age = age;
        num = new char [11];
    }
    ~Stu() = default;

    Stu& growup() {
        this->age++;

        Stu * const p = this;
//        this = nullptr;
        return *this;
    }

    void dis() const {
        std::cout << this->name << " " << this->age << std::endl;
        for (int i = 0; i < 10; ++i) {
            std::cout << num[i];
        }
        std::cout << std::endl;
    }

    //赋值运算符重载
    Stu &operator=(const Stu &other) {
        std::cout << "Operator" << "\n";
        if (&other == this) {
            return *this;
        }
        delete []this->num;
        name = other.name;
        age = other.age;
        this->num = new char [strlen(other.num) + 1];
        strcpy(num, other.num);
        return *this;
    }

private:
    std::string name;
    int age{};
    char *num;
};

int main() {
//    std::cout << sizeof(Stu) << std::endl;

    Stu s("zhangsan", 13);
    s.dis();
    //链式表达
    s.growup().growup().growup().growup();
    s.dis();

    Stu x;
    x = s;
    x.dis();

    return 0;
}

#if 0
class Stu {
public:
    Stu() {
        std::cout << this << std::endl;
    }
    ~Stu() {
        std::cout << this << std::endl;
    }

private:
    std::string name;
    int age;
};

int main() {
    Stu s;
    std::cout << &s << std::endl;

    return 0;
}
#endif