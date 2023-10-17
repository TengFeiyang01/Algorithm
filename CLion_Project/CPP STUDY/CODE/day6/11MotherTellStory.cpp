#include <iostream>
#include <string>
//依赖倒置原则的多态实现

class IReader {
public:
    virtual std::string getContent() = 0;
};

class EBook : public IReader {
public:
    virtual std::string getContent() {
        return "电子书";
    }
};

class PaperBook : public IReader {
public:
    virtual std::string getContent() {
        return "纸质书";
    }
};

class NewsPaper : public IReader {
public:
    virtual std::string getContent() {
        return "报纸";
    }
};

class Mother {
public:
    void tell(IReader *ir) {
        std::cout << ir->getContent() << std::endl;
    }
};


int main() {
    Mother m;
    PaperBook p;
    NewsPaper n;
    EBook e;

    m.tell(&p);
    m.tell(&n);
    m.tell(&e);

    return 0;
}