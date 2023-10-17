#include <bits/stdc++.h>

//unique_ptr 不可拷贝 不可赋值

class A {
public:
    A() {
        std::cout << "A()" << std::endl;
    }
    ~A() {
        std::cout << "~A()" << std::endl;
    }
    static void dis() {
        std::cout << "A::void dis()" << std::endl;
    }
};

void func(std::unique_ptr<A>& a) {

}

int main() {
    A *p = new A;
/*    {
        std::unique_ptr<A> up(p);
        up->dis();
    }*/
    //func(up);  //不可传值 但可以传引用

    //unique_ptr 不允许指向同一个  程序会挂掉 无法避免
    std::unique_ptr<A> up1(p);
//    up1->dis();
//    std::unique_ptr<A> up1(up);  //失败
    if (!up1) {
        std::cout << "No resource!" << std::endl;
    } else {
        //所托管资源的指针
        std::cout << up1.get() << std::endl;
//        std::cout << p << std::endl;
    }

    //返回的是原本的p
//    auto rp = up1.release();
//    delete rp;

    A *p1 = new A;
    //重置 会将原本绑定的资源释放 然后绑定新的资源
    up1.reset(p1);
//    std::cout << p1 << " " << up1.get() << std::endl;

    std::unique_ptr<A> up2 = std::move(up1);

    return 0;
}
