#include <bits/stdc++.h>

//对象的创建, 初始化，挂到渲染树上去

class CCSprite {
public:
    CCSprite() {}

    static CCSprite* create() {
        CCSprite *pRet = new CCSprite;
        if (pRet and pRet->init()) {
            pRet->autoRelease();
        } else {
            delete pRet;
            pRet = nullptr;
        }
        return pRet;
    }

    bool init() {
        std::cout << "initial" << std::endl;
        ch = rand() % 127;
//        std::cout << ch << std::endl;
        return true;
    }

    static void renderTree() {
        CCSprite *t = head;
        while (t) {
            std::cout << t->ch << std::endl;
            t = t->next;
        }
    }

    void autoRelease() {
        this->next = head;
        head = this;
    }

private:
    static CCSprite *head;
    CCSprite *next;
    char ch;
};

CCSprite *CCSprite::head = nullptr;

int main() {

    CCSprite *ps = CCSprite::create();
    CCSprite *ps1 = CCSprite::create();
    CCSprite *ps2 = CCSprite::create();
    CCSprite *ps3 = CCSprite::create();
    CCSprite *ps4 = CCSprite::create();

    CCSprite::renderTree();


    return 0;
}
