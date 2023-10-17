#include <bits/stdc++.h>

//右值引用 解决临时对象带来的效率问题
//栈对象返回没有优化的情况下 产生临时对象 return->objtmp->obj a= 发生两次拷贝

class A {
public:
    A() {
        std::cout << "无参构造 " << this << std::endl;
    }

    A(int i) : data_(i) {
        std::cout << "含参构造 " << this << std::endl;
    }

    A(const A &other) {
        std::cout << "拷贝构造 " << this << " from " << &other << std::endl;
    }

    A &operator=(const A &other) {
        std::cout << "拷贝赋值 " << this << " from " << &other << std::endl;
    }

    ~A() {
        std::cout << "析构函数 " << this << std::endl;
    }

    void dis() {
        std::cout << " ";
        std::cout << data_ << "\n";
    }
    void dis() const {
        std::cout << "const ";
        std::cout << data_ << "\n";
    }
private:
    int data_ = 0;
};

A getObject() {  //拷贝是不可避免的
    return {1};
}

void func(A &a) {  //扩展了对象的作用域

}

void func(A &&a) {

}

long long gl() {
    return 10;
}

int main() {
//    A b = getObject();  //无优化 两次拷贝
    /*
        含参构造 0x6b1d1ff70c
        拷贝构造 0x6b1d1ff708 from 0x6b1d1ff70c
        析构函数 0x6b1d1ff70c
        析构函数 0x6b1d1ff708
    */

/*    A a;
    func(a);  //一次构造 一次拷贝 若加引用只会发生一次无参构造*/

/*    const A& a = getObject();  //常量引用可以防止多次拷贝 const T& 万能引用
    (const_cast<A&> (a)).dis();  //失败 const对象只能调用const函数  对于指针或是引用 可以使用const_cast脱常*/


//    A &&b = getObject();  //右值引用 引用的是临时对象
    /*
        含参构造 0x45c63ffbb4
        析构函数 0x45c63ffbb4
    */

//    func(A());  //调用func(A&&) 发生一次构造

/*    int a = 3;
    const int &ra = 10;  //产生了临时变量 cosnt
    const double &rb = a;
    const long long &rll = gl();*/

    int a = 1;
    int &&ra = 10;  //右值引用 还可以更改
    double &&rda = a;  //a改变不会影响rda的值 引用的是原本的1
    long long &&rll = gl();



    return 0;
}
