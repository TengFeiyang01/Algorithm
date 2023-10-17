#include <iostream>

class Phone {
public:
    virtual int cost() = 0;
};

class Nokia : public Phone {
public:
    int cost() {
        return 4000;
    }
};

class DecoratePhone : public Phone {
public:
    DecoratePhone(Phone *ph) : phone(ph) {}


protected:
    Phone *phone;
};

class ScreenProtectorPhone : public DecoratePhone {
public:
    ScreenProtectorPhone(Phone *ph) : DecoratePhone(ph) {}
    int cost() {
        return 100 + phone->cost();
    }
};

class HeadSetPhone : public DecoratePhone {
public:
    HeadSetPhone(Phone *ph) : DecoratePhone(ph) {}
    int cost() {
        return 200 + phone->cost();
    }
};

int main() {

    Nokia nk;
    std::cout << nk.cost() << std::endl;

    ScreenProtectorPhone sp(&nk);

    std::cout << sp.cost() << std::endl;

//    ScreenProtectorPhone sp2(&sp);
//    std::cout << sp2.cost() << std::endl;

//    HeadSetPhone hp(&sp);
//    std::cout << hp.cost() << std::endl;

    Phone *p = new HeadSetPhone(new HeadSetPhone(new ScreenProtectorPhone(new ScreenProtectorPhone(new Nokia))));

    std::cout << p->cost() << std::endl;


    return 0;
}
