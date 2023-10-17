#include <bits/stdc++.h>

class Student {
    friend std::ostream &operator<<(std::ostream &out, Student &stu);
public:
    Student(std::string name = "", std::string sex = "", double score = 60)
            : name_(name), sex_(sex), score_(score) {}

    Student(const Student &other) {
        std::cout << "Student(const Student &other)" << std::endl;
        this->score_ = other.score_;
        this->name_ = other.name_;
        this->sex_ = other.sex_;
    }

    void dis() {
        std::cout << "name: " << name_ << std::endl;
        std::cout << "sex: " << sex_ << std::endl;
        std::cout << "score:   " << score_ << std::endl;
    }

private:
    double score_;
    std::string name_;
    std::string sex_;
};

std::ostream &operator<<(std::ostream &out, Student &stu) {
    out << stu.name_ << " " << stu.score_ << " " << stu.sex_;
    return out;
}

class Graduate : public Student {
    friend std::ostream &operator<<(std::ostream &out, Graduate &gra) {
        std::cout << static_cast<Student&>(gra) << std::endl;
        std::cout << gra.salary_ << std::endl;
        return out;
    }
public:
    Graduate(std::string name = "", std::string sex = "", double score = 60, double salary = 200)
            : Student(name, sex, score), salary_(salary) {}

    Graduate(const Graduate &other) : Student(other) {
        std::cout << "Graduate(const Graduate &other)" << std::endl;
        this->salary_ = other.salary_;
    }

    void dump() {
        dis();
        std::cout << "salary: " << salary_ << std::endl;
    }

private:
    double salary_;
};

int main() {
    Graduate g("zhangsan", "s", 99, 1000);
/*    g.dump();
    std::cout << "+++++++++++++++++++++++" << std::endl;
    Graduate gg(g);
    gg.dump();*/
    std::cout << g << std::endl;
    return 0;
}
