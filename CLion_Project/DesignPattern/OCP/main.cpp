#include <bits/stdc++.h>

class IReader {
public:
    virtual std::string getContent() {}

    virtual void playBall(){}
};

class Ebook : public IReader {
public:
    std::string getContent() override {
        return "Ebook";
    }
};

class newsPapaper : public IReader {
public:
    std::string getContent() override {
        return "newsPaper";
    }
};

class Mother {
public:
    void tellStory(IReader *ir) {
        std::cout << ir->getContent() << std::endl;
    }
};

class basketball : public IReader {
public:
    void playBall() {
        std::cout << "play basketball!" << std::endl;
    }
};

class Father {
public:
    static void play(IReader *ir) {
        ir->playBall();
    }
};


int main() {
    Ebook e;
    Mother m;
    newsPapaper n;

    m.tellStory(&e);
    m.tellStory(&n);


    Father f;
    basketball fb;
    f.play(&fb);


    return 0;
}
