//
// Created by ytf on 2023/9/20.
//

#include "../headers/LondonTime.h"
#include <iostream>

LondonTime::LondonTime() {

}

void LondonTime::update(int hour, int min, int sec) {
    _hour = hour + 200;
    _min = min + 200;
    _sec = sec + 200;
    dis();
}
