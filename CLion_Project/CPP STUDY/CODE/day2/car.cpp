#include <bits/stdc++.h>
#include <unistd.h>

class Car {
public:
    Car(std::string c = "red", std::string b = "redflag", double o = 0) :color(c), brand(b), oil(o) {}

    void addOil(double val) {
        oil += val;
    }

    void run() {
        if (oil >= 10) {
            std::cout << "running......" << oil << std::endl;
            sleep(1);
            oil -= 10;
            run();
        } else {
            std::cout << "oil not enough, need add gas" << std::endl;
        }
    }
private:
    std::string color, brand;
    double oil;
};

int main() {
    Car c;
    c.addOil(31);
    c.run();

    return 0;
}
