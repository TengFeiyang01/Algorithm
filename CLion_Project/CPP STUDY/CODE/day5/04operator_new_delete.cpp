#include <bits/stdc++.h>

class A {
public:
    A() {
        std::cout << "A()" << std::endl;
    }

    void xxx() {
        std::cout << x << y << std::endl;
    }

    ~A() {
        std::cout << "~A()" << std::endl;
    }

    void *operator new(size_t size) {
        std::cout << size << std::endl;
        std::cout << "operator new" << std::endl;
        void *p = malloc(size);
        ((A *) p)->x = 10;
        ((A *) p)->y = 20;
        return p;
    }

    void operator delete(void *p) {
        std::cout << "operator delete" << std::endl;
        free(p);
    }

    void *operator new[](size_t size) {
        std::cout << size << std::endl;
        std::cout << "operator new[]" << std::endl;

        void *p = malloc(size);
        return p;
    }

    void operator delete[](void *p) {
        free(p);
    }

private:
    int x;
    int y;
};


int main() {
    A *pa = new A[3];

//    int *pi = new int;
//    pa->xxx();
//    delete pa;
    delete []pa;

    return 0;
}
