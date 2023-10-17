//
// Created by ytf on 2023/9/20.
//

#include "../headers/TokyoTime.h"
#include <iostream>

TokyoTime::TokyoTime() {

}

void TokyoTime::update(int hour, int min, int sec) {
    _hour = hour + 100;
    _min = min + 100;
    _sec = sec + 100;
    dis();
}
