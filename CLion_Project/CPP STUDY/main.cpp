#include <iostream>

int main() {

    int auks, bats, coots;
    // 先加后取整


    auks = 19.99 + 11.99;

    bats = int(19.99) + int(11.99);

    coots = (int)19.99 + (int)11.99;

    std::cout << "auks = " << auks << ", bats = " << bats << ", coots = " << coots << std::endl;

    char ch = 'z';

    std::cout << "The Code for " << ch << " is " << int(ch) << std::endl;

    std::cout << "Yes, the code is " << static_cast<int>(ch) << std::endl;

    char grade = 65;
    char c = 'A';

    std::cout << grade << " " << c << std::endl;

    return 0;
}
