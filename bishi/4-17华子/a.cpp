#include <bits/stdc++.h>

using namespace std;

string Stack[1000];
string s[10300];

int main() {

    int n, top = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
    for (int i = 0; i < n; i++) {
            auto c = s[i];
            if (top == 0) {
                    top++;
                    Stack[top] = c;
            } else {
                    if (top >= 2 && Stack[top] == c && Stack[top - 1] == c) {
                            top--;
                            top--;
                    } else {
                            top++;
                            Stack[top] = c;
                    }
            }
    }

    if (tp == 0) {
            cout << 0 << "\n";
    } else {
            for (int i=1; i<=top; i++) {
                    cout << Stack[i] << " \n"[i == top];
            }
    }

    return 0;
}
