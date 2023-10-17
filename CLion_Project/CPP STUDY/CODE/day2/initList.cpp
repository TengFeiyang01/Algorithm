#include <bits/stdc++.h>


class Stack {
public:
    //构造函数  对象生成时自动调用
    Stack() {
        top = -1;
        size = 1024;
        data = new int[1024];
        memset(data, 0, 1024);
    }

    //析构函数
    ~Stack() {
        delete[]data;
        std::cout << "Deleted!" << std::endl;
    }

//    explicit Stack(int max_size = 1024) {
//        top = -1;
//        size = max_size;
//        data = new int[max_size];
//        memset(data, 0, max_size);
//    }

    //初始化列表
    explicit Stack(int max_size = 1024)
            : top(-1), size(max_size), data(new int[max_size]{0}) {}


    int pop() {
        return data[top--];
    }

    void push(int x) {
        if (top != size) {
            data[++top] = x;
        } else {
            return;
        }
    }

    [[nodiscard]] bool isEmpty() const {
        return top == -1;
    }

    [[nodiscard]] bool isFull() const {
        return top == size;
    }

    [[nodiscard]] int capacity() const {
        return size;
    }

private:
    int top, size;
    int *data;
};

int main() {

    Stack s(23);
    for (int x = 1; x < 10; ++x) {
        s.push(x);
    }

    while (!s.isEmpty()) {
        std::cout << s.pop() << std::endl;
    }

    std::cout << s.capacity() << std::endl;


    //new出来的手动释放也会调用析构函数
    auto *p = new Stack(1);
    delete p;

    return 0;
}
