#include <iostream>

class A {
public:
    void update(int add) {
        state += add;
    }
};

class B {
public:
    void update(int add) {
        state += add;
    }
};

class C {
public:
    void update(int add) {
        state += add;
    }
};

class D {
public:
    void notify(A *pa, B *pb, C *pc) {
        pa->update(state + 100);
        pb->update(state + 200);
        pc->update(state + 300);
    }

    void update(int add, A *pa, B *pb, C *pc) {
        state += add;
        notify(pa, pb, pc);
    }
private:
    int state = 0;
};

int main() {
    D d;
    A a;
    B b;
    C c;
    d.update(10, &a, &b, &c);


    return 0;
}
