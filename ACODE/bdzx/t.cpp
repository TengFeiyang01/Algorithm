#include <bits/stdc++.h>

using namespace std;
const int MAXSIZE = 5;

struct Queue {
    int data[MAXSIZE];
    int rear, front;

    // 构造函数 无参数 无返回值 初始化自动调用
    Queue() {
        rear = MAXSIZE - 1;
        front = 0;
    }

    int push(int x) {
        if (isfull()) {
            return -1;
        } 
        rear = (rear + 1) % MAXSIZE;
        data[rear] = x;
        return 0;
    }

    int pop() {
        if (isempty()) {
            return -1;
        }
        int x = data[front];
        front = (front + 1) % MAXSIZE;
        return x;
    }

    bool isfull() {
        return front == (rear + 2) % MAXSIZE;
    }

    bool isempty() {
        return front == (rear + 1) % MAXSIZE;
    }

    int size() {
        if (isempty()) {
            return 0;
        } else if (isfull()) {
            return MAXSIZE - 1;
        } else {
            return (rear + MAXSIZE - front + 1) % MAXSIZE;
        }
    }
};



int main() {
    int x;
    Queue q;
    cout << "Test push" << endl;
    for (int i = 0; i < 5; ++i) {
        int x = q.push(i);
        cout << x << endl;  // 不满输出0 满了输出-1
    }
    cout << "Test size" << endl;
    cout << q.size() << endl;  // expected: 4

    cout << "Test isfull" << endl;
    cout << q.isfull() << endl; // expected: 1

    cout << "Test pop" << endl;
    for (int i = 0; i < 5; ++i) {
        int x = q.pop();
        cout << x << endl;  // 有就输出 没有输出-1
    }

    cout << "Test isempty" << endl;
    cout << q.isempty() << endl;
}
