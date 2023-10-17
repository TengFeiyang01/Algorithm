#include <iostream>

enum CpuType {
    CoreA, CoreB, CoreC
};

class Cpu {
public:
    virtual void work() = 0;
};

class SingleCoreA : public Cpu {
public:
    void work() {
        std::cout << "SingleCoreA work()" << std::endl;
    }
};

class SingleCoreB : public Cpu {
public:
    void work() {
        std::cout << "SingleCoreB work()" << std::endl;
    }
};

class SingleCoreC : public Cpu {
public:
    void work() {
        std::cout << "SingleCoreC work()" << std::endl;
    }
};

class Factory {
public:
    virtual Cpu* createCpu() = 0;
};

class FactoryA : public Factory {
public:
    Cpu * createCpu() override {
        return new SingleCoreA;
    }
};

class FactoryB : public Factory {
public:
    Cpu * createCpu() override {
        return new SingleCoreB;
    }
};


int main() {
/*    Factory fac;
    Cpu *pCpu = fac.createCpu(CoreA);
    pCpu->work();

    pCpu = fac.createCpu(CoreB);
    pCpu->work();*/

    FactoryA fa;
    auto ca = fa.createCpu();
    ca->work();

    FactoryB fb;
    auto cb = fb.createCpu();
    cb->work();

    return 0;
}
