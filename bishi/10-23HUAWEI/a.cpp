#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>  // for sort

using namespace std;

class Product {
public:
    int productId;
    vector<int> repoIds;

    Product(int productId, const vector<int>& repoIds)
        : productId(productId), repoIds(repoIds) {}
};

class CodeStatsSystem {
private:
    // 语言 ID 到语言名称的映射
    vector<string> languageNames = {"c", "c++", "go", "java", "javascript", "python", "rust"};

    // 产品 ID -> (仓库 ID -> (语言 ID -> 代码行数))
    unordered_map<int, unordered_map<int, unordered_map<int, int>>> productStats;

public:
    
    CodeStatsSystem(const vector<Product>& products) {
        // 初始化产品的代码行统计
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
                    product.second[repoId][languageId] = 0; // 代码行数不能为负
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
                        languageCount[lang.first] += lang.second;
                    }
                }
            }
        } else {
            if (productStats.count(productId) > 0) {
                for (const auto& repo : productStats[productId]) {
                    for (const auto& lang : repo.second) {
                        languageCount[lang.first] += lang.second;
                    }
                }
            }
        }

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
    // 示例输入
    vector<Product> products = {
        Product(10, {102, 101}),
        Product(12, {122}),
        Product(22, {221})
    };

    CodeStatsSystem system(products);

    // 示例操作
    system.changeCodelines(221, 3, 2500); // 在 repo 221 中，增加 Java 语言的 2500 行代码
    system.changeCodelines(102, 2, 2100); // 在 repo 102 中，增加 Go 语言的 2100 行代码
    system.changeCodelines(101, 1, 2000); // 在 repo 101 中，增加 C++ 语言的 2000 行代码

    vector<int> result = system.statLanguage(10); // 查询产品 10 的代码行数
    for (int langId : result) {
        cout << langId << " "; // 输出语言 ID
    }
    cout << endl;

    system.changeCodelines(102, 2, -100); // 在 repo 102 中，减少 Go 语言的 100 行代码
    result = system.statLanguage(0); // 查询所有产品的代码行数
    for (int langId : result) {
        cout << langId << " "; 
    }
    cout << endl;

    return 0;
}