//
// Created by ytf on 2023/9/20.
//

#include "../headers/Subject.h"

Subject::Subject() {

}

void Subject::registerObserver(Observer *ob) {
    lo.emplace_back(ob);
}

void Subject::removeObserver(Observer *ob) {
    lo.remove(ob);
}

