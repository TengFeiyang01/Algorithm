//
// Created by ytf on 2023/9/20.
//

#include "../headers/CanadaTime.h"

CanadaTime::CanadaTime() {

}

void CanadaTime::update(int hour, int min, int sec) {
    _hour = hour + 300;
    _min = min + 300;
    _sec = sec + 300;
    dis();
}
