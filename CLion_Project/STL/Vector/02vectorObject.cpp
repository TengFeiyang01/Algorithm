#include <bits/stdc++.h>

//resize > cursize ==> push_back
//resize < cursize ==> pop_back

//reserve 预留空间 而不构造 resize一定会发生构造或析构

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
        std::cout << data_ << "\n";
    }

private:
    int data_ = 0;
};

int main2() {
/*    std::vector<A*> vap;
    vap.reserve(10);

//    vap.push_back(new A);  //没有析构
    auto pa = new A;
    vap.push_back(pa);
    delete pa;*/

    return 0;
}

int main0() {
    std::vector<A> va;
/*    va.reserve(10);
    A a(1);
    //三次拷贝
    va.push_back(a);
    va.push_back(a);
    va.push_back(a);
    std::cout << "------------------------------\n";
    va.insert(va.begin(), a);
    //insert 导致 一次拷贝创建要插入的临时对象 然后进行a[3] = a[2] a[2] = a[1] a[1] = a[0]三次拷贝赋值 再将临时对象放入a[0]*/

    //使用参数30  调用含参构造 再va末尾进行构造
    va.emplace_back(30);
//    va.resize(30);

    return 0;
}

int main1() {
    std::vector<A> va;
//    va.reserve(5);

    va.push_back(A());  //一次构造 一次拷贝
    va.push_back(A());  //一次构造 一次拷贝 此时扩容会导致调用一次复制
    va.push_back(A());  //一次构造 一次拷贝 此时扩容会导致调用一次复制

/*    //此时会放入新的空对象 直接构造在尾部 而非构造后拷贝
    va.resize(3);*/
//    std::cout << "=====================\n";

//    va.resize(2);  //内存为3 resize为2 相当于pop_back() 调用析构

    std::cout << "=====================\n";

    return 0;
}
