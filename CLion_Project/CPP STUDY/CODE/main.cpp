#include <iostream>
#include <time.h>
#include <unistd.h>
#include <iomanip>

class Clock {
public:
    Clock() {
//        auto *pt = localtime(reinterpret_cast<const time_t *>(time(nullptr)));
        auto t = time(nullptr);
        auto pt = localtime(&t);
        hour_ = pt->tm_hour;
        min_ = pt->tm_min;
        sec_ = pt->tm_sec;
    }

    [[noreturn]] void run() {
        while (true) {
            tick();
            display();
        }
    }

    void tick() {
        sleep(1);
        if (++sec_ == 60) {
            sec_ = 0;
            if (++min_ == 60) {
                min_ = 0;
                if (++hour_ == 24) {
                    hour_ = 0;
                }
            }
        }
    }

    void display() {
        std::cout << std::setfill('0') << std::setw(2) << hour_ << ": " << std::setw(2) << min_ << ": " << std::setw(2) << sec_ << std::endl;
    }

private:
    int hour_;
    int min_;
    int sec_;
};

int main() {
    Clock c;
    c.run();

    return 0;
}
