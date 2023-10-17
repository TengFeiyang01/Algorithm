#include <bits/stdc++.h>

class Wing {
public:
    Wing() {
        std::cout << "Wing Create" << std::endl;
    }

    ~Wing() {
        std::cout << "Wing Destroy" << std::endl;
    }
};

class Bird {
public:
    Bird() {
        left = new Wing;
        right = new Wing;
    }

    ~Bird() {
        delete left;
        delete right;
    }

private:
    Wing *left, *right;
};

class Flork {
public:
    void flyin(Bird *b) {
        vb.emplace_back(b);
    }

    Bird *flyout() {
        auto r = vb.back();
        vb.pop_back();
        return r;
    }

private:
    std::vector<Bird *> vb;
    int tot;
};

int main() {
    Bird b1, b2, b3;
    Flork f;

    f.flyin(&b1);
    f.flyin(&b2);
    f.flyin(&b3);

    return 0;
}
