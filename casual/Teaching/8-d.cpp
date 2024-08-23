#include <iostream>
#include <string>
#include <vector>
#include <bitset>

// 将单个十六进制字符转换为四位二进制字符串
std::string hex_char_to_bin(char c) {
    switch (toupper(c)) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
        default:  return ""; // 处理无效输入
    }
}

// 将十六进制字符串转换为二进制字符串
std::string hex_to_binary(const std::string& hex) {
    std::string bin;
    for (char c : hex) {
        bin += hex_char_to_bin(c);
    }
    return bin;
}

// 判断并解析X-UTF编码
int decode_xutf(const std::string& hex_string) {
    if (hex_string.length() % 2 != 0 || hex_string.length() < 2 || hex_string.length() > 12) {
        return -1; // 长度不符合要求
    }

    std::string binary_string = hex_to_binary(hex_string);
    
    // 计算头字节中前导1的个数来确定字节总数
    int byte_count = 0;
    while (byte_count < binary_string.length() && binary_string[byte_count] == '1') {
        ++byte_count;
    }

    if (byte_count == 0) { // 单字节字符
        byte_count = 1;
    } else {
        if (binary_string[byte_count] != '0' || byte_count == binary_string.length()) {
            return -1; // 多字节字符的首字节格式错误
        }
        ++byte_count; // 包含首字节的0
    }

    if (binary_string.length() != byte_count * 8) {
        return -1; // 总长度与字节数不匹配
    }
    
    std::string valid_bits;
    for (int i = 0; i < byte_count; ++i) {
        if (i > 0) {
            // 检查多字节字符后续字节的前缀
            if (binary_string.substr(i * 8, 2) != "10") {
                return -1;
            }
            valid_bits += binary_string.substr(i * 8 + 2, 6);
        } else {
            valid_bits += binary_string.substr(byte_count, 7 - byte_count);
        }
    }

    // 转换有效位为十进制数值
    unsigned long result = std::bitset<32>(valid_bits).to_ulong();

    return static_cast<int>(result);
}

int main() {
    std::string hex_string;
    std::cin >> hex_string;

    int decoded_value = decode_xutf(hex_string);

    std::cout << decoded_value << std::endl;

    return 0;
}
