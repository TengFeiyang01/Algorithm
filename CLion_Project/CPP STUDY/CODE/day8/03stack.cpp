#include <bits/stdc++.h>

//类模板    模板类        类对象
//stack    stack<int>   stack<int> s

//类模板中的友元
//1在声明处 推荐
//2在类外的定义出
//@1 在类内声明 <> 表示是个声明
//@2 在类外实现
//@3 在类的声明的前面 做前向声明 并且在其前做类的前向声明

//模板通常会将声明与实现 放在一个文件 即hpp中
//C/C++的编译模式是 按文件进行编译

template<typename T>
class stack;

template<typename T>
std::ostream& operator<<(std::ostream &out, stack<T> &s);

template<typename T>
class stack {
public:
    stack(int size = 1024) : MAXSIZE(size) {
        space = new T[size + 1];
        top = 0;
    }

    T pop() {
        if (top != 0) {
            return space[top--];
        } else {
            return T();
        }
    }

    void push(T x) {
        if (top != MAXSIZE) {
            space[++top] = x;
        } else {
            return;
        }
    }

    [[nodiscard]] bool isEmpty() const {
        return top == 0;
    }

    [[nodiscard]] bool isFull() const {
        return top == MAXSIZE;
    }

    friend std::ostream& operator<< <>(std::ostream &out, stack<T> &s);

/*    friend std::ostream& operator<<(std::ostream &out, stack<T> &s) {
        for (int i = 1; i <= s.top; ++i) {
            out << s.space[i] << " ";
        }
        return out;
    }*/

private:
    int MAXSIZE = 1024;
    int top;
    T *space;
};

template<typename T>
std::ostream& operator<<(std::ostream &out, stack<T> &s) {
    for (int i = 1; i <= s.top; ++i) {
        out << s.space[i] << " ";
    }
    return out;
}

int main() {
    stack<std::string> stk(20);
    for (int i = 0; i < 12; ++i) stk.push("asasdajklas");
/*    while (!stk.isEmpty()) {
        std::cout << stk.pop() << " ";
    }*/
    std::cout << stk;

    return 0;
}
