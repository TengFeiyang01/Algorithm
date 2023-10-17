#include <bits/stdc++.h>

class Birthday {
public:
    Birthday(int y = 2000, int m = 6, int d = 9)
            : year_(y), month_(m), day_(d) {}

    void disBirth() {
        std::cout << "year: " << year_ << std::endl;
        std::cout << "month:  " << month_ << std::endl;
        std::cout << "day: " << day_ << std::endl;
    }

private:
    int year_;
    int month_;
    int day_;
};

class Student {
public:
    Student(std::string name = "", std::string sex = "", double score = 60)
            : name_(name), sex_(sex), score_(score) {}


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

class Graduate : public Student {
public:
    Graduate(std::string name = "", std::string sex = "", double score = 60, double salary = 200, int y = 2000,
             int m = 6, int d = 9)
            : Student(name, sex, score), birth(y, m, d), salary_(salary) {}

    void dump() {
        dis();
        birth.disBirth();
        std::cout << "salary: " << salary_ << std::endl;
    }

private:
    double salary_;
    Birthday birth;
};

class Doctor : public Graduate {
public:
    Doctor(std::string name, std::string sex, double score, double salary, std::string title)
        : Graduate(name, sex, score, salary), title_(title) {}
        void disDump() {
        dump();
        std::cout << "title: " << title_ << std::endl;
    }
private:
    std::string title_;
};

int main() {
    Doctor y("ytf", "man", 100, 3000, "doctor zhao");

    return 0;
}
