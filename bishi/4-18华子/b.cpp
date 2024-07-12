#include <bits/stdc++.h>

template<typename T>
std::vector<T> input() {
    std::vector<T> a;
    T s;
    while(std::cin >> s) {
        a.push_back(s);
        if(std::cin.get() != ' ') break;
    }
    return a;
}

int main() {
    int n;
    std::cin >> n;

    for (int j = 0; j < n; j++) {
    	auto a = input<std::string>();
        int m = a.size();
	    int absent = 0;
        bool ok = true;

	    int present = 0;

	    std::string pre = "";

	    for (int i = 0; i < m; i++) {
	        if (i >= 7) {
	            if("present" == a[i - 7]) {
	                present--;
	            }
	        }

	        // 当前的考勤记录
	        auto cur = a[i];

	        if ("absent" == cur) {
	            if (++absent > 1) {
	            	ok = false;
	            }
	        } else if (cur == "late" || "leaveearly" == cur) {
	            if (pre == "late" || "leaveearly" == pre) {
	            	ok = false;
	            }
	        } else if ("present" == cur) {
	            present++;
	        }

	        pre = cur;

	        int k = std::min(i + 1, 7);
	        if (k - present > 3) ok = false;
	    }


        std::cout << (ok ? "true" : "false") << " \n"[j == n - 1];
    }

    return 0;
}



