#include <iostream>

class Singleton {
public:
    //static member function can only use static member variety
    static Singleton *getInstance() {
        if (ins == nullptr) {
            ins = new Singleton;
        }
        return ins;
    }

private:
    static Singleton *ins;

    Singleton() {}

    Singleton(const Singleton &) {}

    Singleton &operator=(const Singleton &) {}

    ~Singleton() {}
};

Singleton *Singleton::ins = nullptr;

int main() {

    Singleton *ps = Singleton::getInstance();
    Singleton *ps1 = Singleton::getInstance();

    if (ps == ps1) {
        std::cout << "Victory\n";
    } else {
        std::cout << "Defeat\n";
    }

//    Singleton a(*ps);
//    *ps = *ps;

    return 0;
}
