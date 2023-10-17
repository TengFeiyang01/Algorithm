#include <iostream>
#include <string>
#include <vector>

//引用返回左值
char &get_val(std::string &str, decltype(str.size()) id) {
    return str[id];
}

std::string expected = "abc";
std::string actual = expected;

std::vector<std::string> process() {
    if (expected.empty()) {
        return {};
    } else if (expected == actual) {
        return {"functionX", "okay"};
    } else {
        return {"functionX", expected, actual};
    }
}

const std::string &shorterString(const std::string &s1, const std::string &s2) {
    return s1.size() <= s2.size() ? s1 : s2;
}

std::string &shorterString(std::string &s1, std::string &s2) {
    auto &r = shorterString(const_cast<const std::string&>(s1), const_cast<const std::string&>(s2));

    return const_cast<std::string&>(r);
}


int main() {

    std::string s("a_value");
    std::cout << s << std::endl;
    get_val(s, 0) = 'A';
    std::cout << s << std::endl;

    for (const std::string &str : process()) {
        std::cout << str << " ";
    }



    return 0;
}
