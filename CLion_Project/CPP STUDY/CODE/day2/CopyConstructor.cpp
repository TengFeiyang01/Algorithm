#include <bits/stdc++.h>

//由普通数值做参数完成构造 constructor
//由同类对象做参数完成构造 copy constructor

//shallow copy 如果对象不含有堆上的空间(*)。此时浅拷贝得以满足需求
//不需要自实现
//如果对象包含堆上的空间，需要自行实现deep copy
//浅拷贝会带来 重析构 double free

//copy constructor
//系统提供了默认的拷贝构造器，格式固定，一经实现，不复存在。
//系统提供的拷贝构造器是一种浅拷贝，shallow copy
//deep copy


struct Date {
public:
    //含参构造函数
    explicit Date(int y = 2016, int m = 1, int d = 1) :year(y), month(m), day(d) {}

    Date(const Date &another) {
        year = another.year;
        month = another.month;
        day = another.day;
    }

    void dis() const {
        std::cout << "year:" << year << "month:" << month << "day:" << day << std::endl;
    }

private:
    int year, month, day;
};

int main() {
    //调用构造函数
    Date d(2016, 9, 9);
    d.dis();

    //此时调用的是默认的拷贝构造函数
    Date d1(d);
    d1.dis();

    return 0;
}
