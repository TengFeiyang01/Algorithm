#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

struct people {
	std::string name;
	int height;
	char sex;
};

void solve() {
  	int n;
  	std::cin >> n;
    if (n > 100) {
        std::cout << "PARA ERROR";
        return;
    }
  	std::vector<people> male, female;
  	for (int i = 0; i < n; ++i) {
  		std::string name;
  		int height;
  		char sex;
  		std::cin >> name >> height >> sex;
        if (height <= 100 || height >= 200) {
            std::cout << "PARA ERROR";
            return;
        }
    	if (sex == 'F') {
  			female.push_back({name, height, sex});
  		} else {
  			male.push_back({name, height, sex});
  		}
  	}  
  	std::sort(male.begin(), male.end(), [&](auto &x, auto &y){
  		if (x.height != y.height) {
  			return x.height < y.height;
  		} else {
  			return x.name < y.name;
  		}
  	});
  	std::sort(female.begin(), female.end(), [&](auto &x, auto &y){
  		if (x.height != y.height) {
  			return x.height < y.height;
  		} else {
  			return x.name < y.name;
  		}
  	});  	
  	int i = 0, j = 0;
  	int a = male.size(), b = female.size();
  	std::vector<people> res;
  	while (i < a || j < b) {
  		if (j < b) {
  			res.push_back(female[j]);
  			j++;
  		}
  		if (i < a) {
  			res.push_back(male[i]);
  			i++;
  		}
  	}
  	
  	for (int i = 0; i < n; ++i) {
  		std::cout << res[i].name << " " << res[i].height << " " << res[i].sex;
  		if (i != n - 1) {
  			std::cout << "\n";
  		}
  	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
