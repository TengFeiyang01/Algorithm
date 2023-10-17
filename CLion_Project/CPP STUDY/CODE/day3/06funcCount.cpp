#include <bits/stdc++.h>

class University {
public:
    University(std::string t = "", std::string l = "") :tower_(t), lake_(l) {}

    static std::string lib_;
    void dis() {
        std::cout << "塔：" << tower_ << " 湖：" << lake_ << " 图：" << lib_ << std::endl;
    }

    //通过返回引用的方式 修改私有成员
    std::string& getLib() {
        return lib_;
    }

//    std::string& getTwoer() {
//        return tower_;
//    }

private:
    std::string tower_;
    std::string lake_;
};

std::string University::lib_ = "";

int main() {
    University Peking("博雅塔", "未名湖");
    University bs("电视塔", "大明湖");
    University xdf("雷峰塔", "西湖");

    Peking.lib_ += "九阴真经";
    Peking.dis();
    bs.lib_ += "挖掘机技术哪家强";
    bs.dis();
    xdf.lib_ += "要出国，找我学英语";
    xdf.dis();

    return 0;
}

#if 0
//static 修饰函数，目的是为了管理静态变量

class A {
public:
    void foo() {
        count += 1;
    }

    static int invokeCount() {
        return count;
    }

    void func() {

    }
//private:
    int m_, n_;
    static int count;
};

//类外初始化
int A::count = 0;

int main() {

    {
        A a, b, c;
        a.foo();
        b.foo();
        c.foo();

//        std::cout << a.invokeCount() << std::endl;
    }

    std::cout << A::invokeCount() << std::endl;

    std::cout << A::count << std::endl;

    return 0;
}
#endif