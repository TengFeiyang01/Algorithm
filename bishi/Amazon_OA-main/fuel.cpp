#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;


int solution(vector<int>& A, int X, int Y, int Z) {
    int n = A.size();
    vector<int> pumps = {X, Y, Z};
    vector<int> end(3, 0);
    for (int i = 0; i < n; ++i) {
        bool ok = false;

        for (int j = 0; j < 3; ++j) {
            if (pumps[j] >= A[i]) {
                pumps[j] -= A[i];
                end[j] += A[i];
                ok = true;
                break;
            }
        }

    }
   
}

int main() {
    vector<int> A1 = {2, 8, 4, 3, 2};
    int X1 = 7;
    int Y1 = 11;
    int Z1 = 3;
    int result1 = solution(A1, X1, Y1, Z1);
    cout << "最大等待时间: " << result1 << endl; // 输出应为8

    vector<int> A2 = {5};
    int X2 = 4;
    int Y2 = 0;
    int Z2 = 3;
    int result2 = solution(A2, X2, Y2, Z2);
    cout << "最大等待时间: " << result2 << endl; // 输出应为-1

    return 0;
}