#include <iostream>


class Weapon {
public:
    virtual void use() = 0;

};

class Knife : public Weapon {
public:
    void use() override {
        std::cout << "use knife kill you!" << std::endl;
    }
};

class Gun : public Weapon {
public:
    void use() override {
        std::cout << "use gun kill you!" << std::endl;
    }
};

class Sprite {
public:
    Sprite(Weapon *wp) {
        _wp = wp;
    }

    void setWeapon(Weapon *wp) {
        _wp = wp;
    }

    void fight() {
        _wp->use();
    }

private:
    Weapon *_wp;
};

int main() {

    Knife nf;
    Gun g;
    Sprite sp(&nf);
    sp.fight();

    sp.setWeapon(&nf);
    sp.fight();

    return 0;
}
