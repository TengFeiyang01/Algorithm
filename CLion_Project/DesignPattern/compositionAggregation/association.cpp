#include <bits/stdc++.h>

//普通关联

class Student;
class Teacher {
public:
    void addStudent(Student *s) {
        vs.emplace_back(s);
    }

private:
    std::vector<Student*> vs;
};

class Student {
public:
    void addTeacher(Teacher *t) {
        vt.emplace_back(t);
    }
private:
    std::vector<Teacher*> vt;
};

int main() {
    //你中有我 我中有你
    auto t1 = new Teacher, t2 = new Teacher, t3 = new Teacher;
    auto s1 = new Student, s2 = new Student, s3 = new Student;

    t1->addStudent(s1);
    t1->addStudent(s2);
    t1->addStudent(s3);

    s2->addTeacher(t1);
    s2->addTeacher(t1);
    s2->addTeacher(t1);

    return 0;
}
