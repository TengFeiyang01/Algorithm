#include <bits/stdc++.h>

class Game {
public:
    Game() {
        pf[0] = &Game::f;
        pf[1] = &Game::g;
        pf[2] = &Game::h;
        pf[3] = &Game::l;
    }

    void select(int i) {
        if (i >= 0 and i <= 3) {
            (this->*pf[i])(i);
        }
    }
private:
    void f(int idx) {
        std::cout << "void f(int idx)" << std::endl;
    }

    void g(int idx) {
        std::cout << "void f(int idx)" << std::endl;
    }

    void h(int idx) {
        std::cout << "void f(int idx)" << std::endl;
    }

    void l(int idx) {
        std::cout << "void f(int idx)" << std::endl;
    }

    enum {
        nc = 4
    };

    //pf是数组名 类型是 void (Game::*)(int idx)
    void (Game::*pf[nc])(int idx);
};

int main() {
    Game g;
    g.select(1);
    g.select(2);
    g.select(3);

    return 0;
}
