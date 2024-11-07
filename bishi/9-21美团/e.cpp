#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    size_t start = 0, end = 0;

    while ((end = str.find(delimiter, start)) != std::string::npos) {
        if (end != start) {
            tokens.push_back(str.substr(start, end - start));
        }
        start = end + 1;
    }

    if (end != start) {
        tokens.push_back(str.substr(start));
    }

    return tokens;
}

int main() {
    std::string op, s;
    std::cin >> op;
    std::cin.ignore(); 
    std::getline(std::cin, s);

    bool found = false;
    int start = 0, end;

    while ((start = s.find('[', start)) != std::string::npos && (end = s.find(']', start)) != std::string::npos) {
        std::string entry = s.substr(start + 1, end - start - 1);
        std::size_t key_end = s.rfind(op, start);

        if (key_end != std::string::npos && key_end + op.length() == start) {
            std::vector<std::string> parts = split(entry, ',');
            if (parts.size() == 3) {
                std::string addr_part = parts[0];
                std::string mask_part = parts[1];
                std::string val_part = parts[2];

                if (addr_part.find("addr=") == 0 && mask_part.find("mask=") == 0 && val_part.find("val=") == 0) {
                    std::string addr = addr_part.substr(5);
                    std::string mask = mask_part.substr(5);
                    std::string val = val_part.substr(4);

                    std::cout << addr << " " << mask << " " << val << std::endl;
                    found = true;
                }
            }
        }

        start = end + 1; // 移动到下一个可能的起始位置
    }

    if (!found) {
        std::cout << "FAIL" << std::endl;
    }

    return 0;
}
