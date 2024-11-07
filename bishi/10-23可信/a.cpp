#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm> // for sort

using namespace std;

class Product {
public:
    int productId;
    std::vector<int> repoIds;

    Product() : productId(0), repoIds() {}

    Product(int productId, const std::vector<int>& repoIds)
        : productId(productId), repoIds(repoIds) {}
};


class CodeStatsSystem {
private:
    vector<string> languageNames = {"c", "c++", "go", "java", "javascript", "python", "rust"};

    unordered_map<int, unordered_map<int, unordered_map<int, int>>> productStats;

public:
    CodeStatsSystem(const vector<Product>& products) {
        for (const auto& product : products) {
            for (int repoId : product.repoIds) {
                productStats[product.productId][repoId] = unordered_map<int, int>();
            }
        }
    }

    // 修改代码行数
    int changeCodelines(int repoId, int languageId, int codeline) {
        for (auto& product : productStats) {
            if (product.second.count(repoId) > 0) {
                product.second[repoId][languageId] += codeline;
                if (product.second[repoId][languageId] < 0) {
                    product.second[repoId][languageId] = 0; 
                }
                return product.second[repoId][languageId];
            }
        }
        return 0;
    }

    vector<int> statLanguage(int productId) {
        map<int, int> languageCount;
        if (productId == 0) {
            for (const auto& product : productStats) {
                for (const auto& repo : product.second) {
                    for (const auto& lang : repo.second) {
                    	if (lang.second) {
                        	languageCount[lang.first] += lang.second;
                    	}
                    }
                }
            }
        } else {
            if (productStats.count(productId) > 0) {
                for (const auto& repo : productStats[productId]) {
                    for (const auto& lang : repo.second) {
                    	if (lang.second) {
	                        languageCount[lang.first] += lang.second;
                    	}
                    }
                }
            }
        }

        // 按代码行数降序排序
        vector<pair<int, int>> sortedLanguageCount(languageCount.begin(), languageCount.end());
        sort(sortedLanguageCount.begin(), sortedLanguageCount.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });

        vector<int> result;
        for (const auto& lang : sortedLanguageCount) {
            result.push_back(lang.first);
        }

        return result;
    }
};

int main() {
    // 初始化样例二的输入
    vector<Product> products = {
        Product(10, {102, 101})
    };

    CodeStatsSystem system(products);

    vector<int> result = system.statLanguage(0); 
    if (result.empty()) {
        cout << "[]" << endl;
    } else {
        for (int langId : result) {
            cout << langId << " ";
        }
        cout << endl;
    }

    std::cout << system.changeCodelines(102, 2, 100) << "\n";

    result = system.statLanguage(0); 
    if (result.empty()) {
        cout << "[]" << endl; 
    } else {
        for (int langId : result) {
            cout << langId << " ";
        }
        cout << endl;
    }
    std::cout << system.changeCodelines(102, 2, -100) << "\n";

    result = system.statLanguage(0); 
    if (result.empty()) {
        cout << "[]" << endl; // 预期输出：[]
    } else {
        for (int langId : result) {
            cout << langId << " ";
        }
        cout << endl;
    }

    return 0;
}
