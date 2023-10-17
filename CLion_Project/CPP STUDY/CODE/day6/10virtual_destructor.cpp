#include <bits/stdc++.h>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

int main() {
//    Dog d;
//    Cat c;
//    d.voice();
//    c.voice();

    Animal *ps = new Dog;
    ps->voice();

    //尚未析构子类 仅仅析构了父类
    delete ps;


    return 0;
}
