#include <iostream>
#include <vector>
#include <algorithm>

bool isValid(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit == 2 || digit == 4) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int n;
        std::cin >> n;

        std::vector<int> a;
        
        for (int i = 1; i < n; ++i) {
            if (isValid(i)) {
                a.push_back(i);
            }
        }

        int count = 0;
        int left = 0, right = a.size() - 1;

        while (left < right) {
            int target = n - a[left];
            int low = left + 1, high = right;
            while (low < high) {
                int sum = a[low] + a[high];
                if (sum == target) {
                    count++;
                    low++;
                    high--;
                } else if (sum < target) {
                    low++;
                } else {
                    high--;
                }
            }
            left++;
        }
        std::cout << count << "\n";
    }

    return 0;
}
