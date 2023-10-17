#include <bits/stdc++.h>

class Furniture {
public:
    void discript() {
        std::cout << "weight_: " << weight_ << std::endl;
        std::cout << "color_: " << color_ << std::endl;
    }
protected:
    float weight_;
    int color_;
};

class Sofa : virtual public Furniture {
public:
    Sofa(float w = 0, int c = 1) {
        weight_ = w;
        color_ = c;
    }
    void sit() {
        std::cout << "take a sit and have a rest" << std::endl;
    }
};

class Bed : virtual public Furniture {
public:
    Bed(float w = 0, int c = 1) {
        weight_ = w;
        color_ = c;
    }
    void sleep() {
        std::cout << "have a sleep ......" << std::endl;
    }
};

class SofaBed : public Sofa, public Bed {
public:
    SofaBed(float w, int c) {
        weight_ = w;
        color_ = c;
    }
};

int main() {
    SofaBed sb(1, 2);
    sb.sit();
    sb.sleep();
    sb.discript();

    return 0;
}
