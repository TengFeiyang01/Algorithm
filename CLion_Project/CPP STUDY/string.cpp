#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cout << sizeof(std::string) << " " << sizeof(s) << std::endl;  //32 32

    /*
    std::string s1 = "penguin";
    std::string s2, s3;

    //string assignment
    std::cout << "You can assign one string object to another: s2 = s1\n";
    s2 = s1;
    std::cout << "s1: " << s1 << ", s2: " << s2 << std::endl;
    std::cout << "You can assign a C-style string to a string object.\n";
    std::cout << "s2 = \"buzzard\"\n";
    s2 = "buzzard";
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "You can assign concatenate string: s3 = s1 + s2\n";
    s3 = s1 + s2;
    std::cout << "s3: " << s3 << std::endl;


    //string I/O
    std::string str1;
    std::cout << "You can use std::getline() to read one line and save it to string object\n";
    std::cout << "Enter a line of text\n";
    std::getline(std::cin, str1);
    std::cout << "You entered: " << str1 << std::endl;
    */

    return 0;
}