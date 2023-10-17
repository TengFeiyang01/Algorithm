#include <bits/stdc++.h>

//shared_ptr 解决了auto_ptr中引用同一个对象所产生的重析构问题
//原理：内部保持一个引用计数  当且仅当引用计数为0时才可以被释放 不可用数组

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

void func(std::shared_ptr<A> &sp) {
    sp.reset();
    std::cout << sp.use_count() << std::endl;
}

int main() {
    std::shared_ptr<A> sp(new A);
    std::shared_ptr<A> sp3(sp);
/*    std::shared_ptr<A> sp2(sp);
//    func(sp);
    std::cout << sp.use_count() << std::endl;
    //移动不会导致计数增加
    std::shared_ptr<A> spm = std::move(sp);

    std::cout << sp3.use_count() << std::endl;
    std::cout << spm.use_count() << std::endl;
    std::cout << sp2.use_count() << std::endl;*/

    func(sp);
    std::cout << sp.use_count() << std::endl;
    std::cout << sp3.use_count() << std::endl;
    return 0;
}

#if 0
int main() {
    std::shared_ptr<A> sp(new A);
    std::cout << sp.use_count() << std::endl;
    func(sp);
    if (sp.unique()) {
        std::cout << "unique" << std::endl;
    }
    std::cout << sp.use_count() << std::endl;

    return 0;
}
#endif

#if 0
int main() {
    A *p = new A;
    {
        std::shared_ptr<A> sp(p);
        std::shared_ptr<A> sp1(sp);
        std::shared_ptr<A> sp2(sp);

        std::cout << sp.use_count() << std::endl;
        sp.reset();  //reset填空 释放资源  reset 只会释放一次(只管自己的) sp1和sp2管不到
        sp2.reset();
        sp1.reset();

        std::cout << sp.use_count() << std::endl;
        std::cout << sp1.use_count() << std::endl;

        std::cout << "-----------------------\n";
    }
    std::cout << "===========================\n";
}
#endif

#if 0
int main() {
    int *p = new int(10);
    std::shared_ptr<int> sp(p);
    std::cout << *sp << std::endl;
    //共享的原因———引用计数
    std::shared_ptr<int> sp1(sp);
    std::cout << sp.use_count() << std::endl;


    return 0;
}
#endif