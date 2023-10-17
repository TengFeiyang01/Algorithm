#include <bits/stdc++.h>
//shallow copy 如果对象不含有堆上的空间(*)。此时浅拷贝得以满足需求
//不需要自实现
//如果对象包含堆上的空间，需要自行实现deep copy
//浅拷贝会带来 重析构 double free

//copy constructor
//系统提供了默认的拷贝构造器，格式固定，一经实现，不复存在。
//系统提供的拷贝构造器是一种浅拷贝，shallow copy
//deep copy

//同类对象方法中进行传参，可以访问其私有成员，其他则不可

class DataStr {
public:
    DataStr() {
        _str = new char [1024];
        strcpy(_str, "C++ is the best language in the world\n");
    }

    //深拷贝 deepcopy
    DataStr(const DataStr &another) {
        _str = new char [strlen(another._str) + 1];
        strcpy(_str, another._str);
    }

    ~DataStr() {
        delete []_str;
    }

    void dis() {
        std::cout << _str << std::endl;
    }
private:
    char *_str;
};

int main() {
    DataStr ds;
    ds.dis();

    //如果提供了析构函数 但没有提供深拷贝 会挂掉
    DataStr ds1(ds);
    ds1.dis();

    DataStr(ds).dis();

    return 0;
}
