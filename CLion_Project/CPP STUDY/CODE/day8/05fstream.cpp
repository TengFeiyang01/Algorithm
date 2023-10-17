#include <bits/stdc++.h>

/*class myfstream {
public:
    myfstream(const char *path, const char *mode) {
        pf = fopen(path, mode);
        if (!pf) {
            flag = false;
        }
        flag = true;
    }
    bool operator!() {
        return !flag;
    }
private:
    FILE *pf;
    bool flag;
};*/

int main() {
//    std::fstream fs("abc.txt", std::ios::in | std::ios::out | std::ios::trunc);
/*
    myfstream msfs("abc.txt", "w+");
    if (!msfs) {
        std::cout << "ABC" << "\n";
    }
*/

    std::ifstream ifile;  //定义一个文件输入流对象
    std::ofstream ofile;  //定义一个文件输出流对象
    std::fstream fs;  //定义一个文件输入/输出流对象

    fs.open("abc.txt", std::ios::in | std::ios::out);

/*    fs << 3;
    int s;
    fs.seekg(0, std::ios::beg);

    fs >> s;
    std::cout << s << "\n";*/

    for (auto i = 'a'; i < 'z'; ++i) {
//        fs.put(i);
        fs << i;
    }

    //读取方式一
    char ch;
    //读取前先定位
    fs.seekg(0, std::ios::beg);

/*    while (fs.get(ch)) {
        std::cout << ch << "\n";
    }*/

    //读取方式二
/*    while (fs >> ch) {
        std::cout << ch << "\n";
    }*/

    std::string s;
    fs >> s;
    std::cout << s << "\n";

    fs.close();

    return 0;
}
