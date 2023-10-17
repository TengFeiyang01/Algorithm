#include <bits/stdc++.h>

class Test {
public:
    Test() {}
    Test(int max) {
        std::cout << "Test(int max)" << std::endl;
        this->mx = max > 0 ? max : 100;
    }
    Test(int max, int min) : Test(max) {
        std::cout << "Test(int max, int min) : Test(max)" << std::endl;
        this->mn = mn > 0 && mn < max ? mn : 1;
    }
    Test(int max, int min, int md) : Test(max, min) {
        std::cout << "Test(int max, int min, int md) : Test(max, min)" << std::endl;
        this->mid = md < max && md > min ? md : 50;
    }
private:
    int mx, mn, mid;
};

int main() {
    Test(1, 2, 3);


    return 0;
}
