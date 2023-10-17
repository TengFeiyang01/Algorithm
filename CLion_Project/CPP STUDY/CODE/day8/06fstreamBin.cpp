#include <bits/stdc++.h>

struct Student {
    std::string name;
    int num;
    int age;
    char sex;
};

int main() {
    std::fstream fs("abc.txt", std::ios::in | std::ios::out | std::ios::trunc | std::ios::binary);

    Student s[3]{{"li", 1001, 19, 'f'}, {"zhang", 1002, 18, 'm'}, {"zheng", 1003, 23, 'f'}};

    fs.write(reinterpret_cast<char *>(&s), sizeof s);

    fs.seekg(0, std::ios::beg);

    Student a;
    while (fs.read(reinterpret_cast<char *>(&a), sizeof(a))) {
        std::cout << a.name << " " << a.num << " " << a.age << " " << a.sex << "\n";
    }

    fs.close();

    return 0;
}
