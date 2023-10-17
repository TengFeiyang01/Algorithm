#include <bits/stdc++.h>

struct Date {
    int year = 1970;
    int month = 1;
    int day = 1;

    void init() {
        std::cin >> year >> month >> day;
    }

    void disDate() const {
        std::cout << year << " " << month << " " << day << std::endl;
    }

    //判断闰年
    [[nodiscard]] bool isLeapYear() const {
        return (year % 4 == 0 && year% 100 or year % 400 == 0);
    }
};


int main() {
    Date d{};
    Date d2 = {2000, 1, 1};

    std::cout << (d2.isLeapYear() ? "Leap Year" : "Not Leap year");

    return 0;
}
