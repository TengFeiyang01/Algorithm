#include <bits/stdc++.h>

#if 0
struct Stack {
    static void init(Stack &s) {
        s.top = 0;
        memset(s.data, 0, 1024);
    }

    int pop() {
        if (top != -1) {
            return data[top--];
        } else {
            return -1;
        }
    }

    void push(int x) {
        if (top != 1023) {
            data[++top] = x;
        } else {
            return;
        }
    }

    [[nodiscard]] bool isEmpty() const {
        return top == -1;
    }

    [[nodiscard]] bool isFull() const {
        return top == 1024;
    }
private:
    int top = -1;
    int data[1024]{};
};
#endif

class Stack {
public:
    static void init(Stack &s) {
        s.top = 0;
        memset(s.data, 0, 1024);
    }

    int pop() {
        if (top != -1) {
            return data[top--];
        } else {
            return -1;
        }
    }

    void push(int x) {
        if (top != 1023) {
            data[++top] = x;
        } else {
            return;
        }
    }

    [[nodiscard]] bool isEmpty() const {
        return top == -1;
    }

    [[nodiscard]] bool isFull() const {
        return top == 1024;
    }
private:
    int top = -1;
    int data[1024]{};
};


int main() {
    Stack s;
    for (int x = 1; x < 10; ++x) {
        s.push(x);
    }

    while (!s.isEmpty()) {
        std::cout << s.pop() << std::endl;
    }

    return 0;
}
