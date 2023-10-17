#include <bits/stdc++.h>

class Sofa {
public:
    void sit() {
        std::cout << "take a sit and have a rest" << std::endl;
    }

};

class Bed {
public:
    void sleep() {
        std::cout << "have a sleep ......" << std::endl;
    }
};

class SofaBed : public Sofa, public Bed {
public:

};

int main() {
    SofaBed sb;
    sb.sit();
    sb.sleep();

    return 0;
}
