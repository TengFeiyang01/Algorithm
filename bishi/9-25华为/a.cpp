#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generate_sums(const vector<int>& tasks, vector<int>& sums, int start, int end) {
    int n = end - start;
    for (int i = 0; i < (1 << n); ++i) {
        int total = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                total += tasks[start + j];
            }
        }
        sums.push_back(total);
    }
}

int max_budget_tasks(const vector<int>& tasks, int T) {
    int n = tasks.size();
    vector<int> left_sums, right_sums;

    generate_sums(tasks, left_sums, 0, n / 2);
    generate_sums(tasks, right_sums, n / 2, n);

    sort(right_sums.begin(), right_sums.end());

    int max_sum = 0;

    for (int sum : left_sums) {
        if (sum > T) continue; 

        int remaining = T - sum;
        auto it = upper_bound(right_sums.begin(), right_sums.end(), remaining);
        if (it != right_sums.begin()) {
            --it;
            max_sum = max(max_sum, sum + *it);
        }
    }

    return max_sum;
}

int main() {
    int n, T;
    cin >> n >> T;
    vector<int> tasks(n);

    for (int i = 0; i < n; ++i) {
        cin >> tasks[i];
    }

    int result = max_budget_tasks(tasks, T);
    cout << result << endl;

    return 0;
}
