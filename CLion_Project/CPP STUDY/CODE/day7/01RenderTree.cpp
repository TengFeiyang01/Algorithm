#include <bits/stdc++.h>
#include <zconf.h>

class RenderShape {
public:
    virtual void show() = 0;

    bool init(int x, int y) {
        x_ = x;
        y_ = y;
        return true;
    }

    static void RenderShapeList() {
        RenderShape *t = head;
        while (t) {
            t->show();
            t = t->next;
        }
    }

/*    void autoRelease() {
        this->next = nullptr;
        head = this;
    }*/

protected:
    int x_;
    int y_;

    static RenderShape *head;
    RenderShape *next;
};

RenderShape *RenderShape::head = nullptr;

class Rect : public RenderShape {
public:
    static Rect *create(int x, int y, int w, int l) {
        Rect *pRet = new Rect;
        if (pRet && pRet->init(x, y, w, l)) {
            pRet->autoRelease();
        } else {
            delete pRet;
            pRet = nullptr;
        }
    }

    //类似于链表的头插法
    void autoRelease() {
        this->next = head;
        head = this;
    }

    bool init(int x, int y, int w, int l) {
        RenderShape::init(x, y);
        w_ = w;
        l_ = l;
        return true;
    }

    virtual void show() {
        std::cout << "draw Rect from (" << x_ << ", " << y_ << ")" << " Width" << w_
                  << " length" << l_ << std::endl;
    }

protected:
    int w_;
    int l_;
};

class Circle : public RenderShape {
public:
    static Circle *create(int x, int y, int r) {
        Circle *pRet = new Circle;
        if (pRet && pRet->init(x, y, r)) {
            pRet->autoRelease();
        } else {
            delete pRet;
            pRet = nullptr;
        }
    }

    void autoRelease() {
        this->next = head;
        head = this;
    }

    bool init(int x, int y, int r) {
        RenderShape::init(x, y);
        r_ = r;
        return true;
    }

    virtual void show() {
        std::cout << "draw Circle from (" << x_ << ", " << y_ << ")" << " Radius" << r_ << std::endl;
    }

protected:
    int r_;
};

class Ellipse : public RenderShape {
public:
    static Ellipse *create(int x, int y, int l, int s) {
        Ellipse *pRet = new Ellipse;
        if (pRet && pRet->init(x, y, l, s)) {
            pRet->autoRelease();
        } else {
            delete pRet;
            pRet = nullptr;
        }
    }

    void autoRelease() {
        this->next = head;
        head = this;
    }

    bool init(int x, int y, int l, int s) {
        RenderShape::init(x, y);
        l_ = l;
        s_ = s;
        return true;
    }

    virtual void show() {
        std::cout << "draw Ellipse from (" << x_ << ", " << y_ << ")" << " long_axis " << l_
                  << " short_axis" << s_ << std::endl;
    }

protected:
    int l_;  //长轴
    int s_;  //短轴
};

void threadTask() {
    while (1) {
        std::cout << "+++++++++++++++++++++++++"<<std::endl;
        RenderShape::RenderShapeList();
        std::cout << "-------------------------" <<std::endl;
        sleep(2);
    }
}

int main() {

    Rect *pr;
    Circle *pc;
    Ellipse *pe;

    std::thread t(threadTask);

    while (1) {
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                pr = Rect::create(1, 2, 3, 4);
                break;
            case 2:
                pc = Circle::create(4, 5, 6);
                break;
            case 3:
                pe = Ellipse::create(7, 8, 9, 10);
                break;
        }
//        RenderShape::RenderShapeList();
    }
    threadTask();
    t.join();



    return 0;
}
