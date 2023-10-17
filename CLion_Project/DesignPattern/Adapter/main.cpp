#include <iostream>

class Goat {
public:
    virtual void miemie() = 0;
};

class NormalGoat : public Goat {
public:
    void miemie() {
        std::cout << "I am a truly Goat!!!" << std::endl;
    }
};

class Wolf {
public:
    void howl() {
        std::cout << "I am a truly Wolf!!!" << std::endl;
    }
};

class AdapterGoat : public Goat {
public:
    AdapterGoat(Wolf *w) : _w(w) {}
    void miemie() {
        _w->howl();
    }
protected:
    Wolf *_w;
};

int main() {

    NormalGoat ng;
    ng.miemie();

    Wolf w;
    w.howl();

    AdapterGoat ag(&w);
    ag.miemie();

    return 0;
}
