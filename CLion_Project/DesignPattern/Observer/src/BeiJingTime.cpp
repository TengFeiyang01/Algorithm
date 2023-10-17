//
// Created by ytf on 2023/9/20.
//

#include "../headers/BeiJingTime.h"

BeiJingTime::BeiJingTime() {

}

void BeiJingTime::setTime(int hour, int min, int sec) {
    _hour = hour;
    _min = min;
    _sec = sec;
    dis();
    notify();
}

void BeiJingTime::notify() {
    for (auto &ob : lo) {
        ob->update(_hour, _min, _sec);
    }
}
