#include <bits/stdc++.h>

/*
    ios::app
    添加输出
    ios::ate
    当已打开时寻找到EOF
    ios::binary
    以二进制模式打开文件
    ios::in
    为读取版打开文件
    ios::out
    为写入打开文件
*/

int main() {
/*    std::fstream fs("fstream.txt", std::ios::in | std::ios::out | std::ios::trunc);  //w+
    if (!fs) {
        std::cout << "Open error" << std::endl;
    }

    fs << 1 << " " << 2 << " " << 3;

    fs.seekg(0, std::ios::beg);

    int a, b, c;
    fs >> a >> b >> c;
    std::cout << a << " " << b << " " << c << std::endl;*/

    //设置宽度填充c  生效一次
//    std::cout << std::setw(4) << std::setfill('0') << 1 << " " << 2 << std::endl;  /0001 2

//    std::cout.put('a');  //输出单个字符
//    std::cout.write("asdkasdjkadsk", 10);  //输出char*

    //std::istream& get(char*s, streamsize n)  终止符为'\n'
    //std::istream& get(char c)
    //std::istream& get(char*s, streamsize n, char delim)   终止符为delim

    char buf[1024];
/*    while (std::cin.get(buf, 10, 'x')) {
        //每次读入9个
        std::cout << buf << "\n";
    }*/

    //std::istream& getline(char *s, streamsize n)
    //std::istream& getline(char *s, streamsize n, char delim)

    /*while (std::cin.getline(buf, 10, 'c')) {
        //每次读入9个 最后一个是休止符
        std::cout << buf << "\n";
    }*/

    //ilike c/ ilikec++/dasasd
    std::cin.get(buf, 20, '/');
    std::cout << buf << "\n";  //ilike c
    std::cin.ignore(10, 'i'); //忽略10个到i包括i为止
    std::cin.putback('i');
    char peek = std::cin.peek();
    std::cout << peek << std::endl;
    std::cin.get(buf, 20, '/');
    std::cout << buf << "\n";  //ilikec++


    //std::istream& getline(std::istream &is, std::string &str, char delim)


    return 0;
}
