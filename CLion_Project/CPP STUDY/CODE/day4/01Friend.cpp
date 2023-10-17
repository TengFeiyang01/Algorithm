#include <bits/stdc++.h>

//friend 友元解决效率问题
//set 和 get 方法，是标准封装的结果，friend破坏了这种封装 但是带来了效率的提高

class Sprite {
public:
    Sprite(int lb = 100) : lifeBlood_(lb) {}

    int getLifeBlood() {
        return lifeBlood_;
    }

    void setLifeBlood(int lb) {
        lifeBlood_ = lb;
    }

private:
    friend void fight(Sprite &sp);
    int lifeBlood_;
};

void fight(Sprite &sp) {
    sp.lifeBlood_ -= 20;
    std::cout << sp.lifeBlood_ << std::endl;
}


//效率过低
//void fight(Sprite &sp) {
//    sp.setLifeBlood(sp.getLifeBlood() - 20);
//    std::cout << sp.getLifeBlood() << std::endl;
//}

int main() {
    Sprite sp;
    fight(sp);

    return 0;
}
