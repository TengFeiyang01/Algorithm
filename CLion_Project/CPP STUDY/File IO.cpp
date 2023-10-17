#include <iostream>
#include <fstream>

int main() {
    char automobile[50];
    int year;
    double a_price, d_price;

    std::ofstream outFlie;
    //将outFlie关联到file_IO.txt
    outFlie.open("file_IO.txt");

    std::cout << "Enter the make and model of automobile: ";
    std::cin.getline(automobile, 50);
    std::cout << "Enter the model year: ";
    std::cin >> year;
    std::cout << "Enter the original asking price: ";
    std::cin >> a_price;
    d_price = 0.913 * a_price;

    //display information on screen with cout
    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout.setf(std::ios_base::showpoint);
    std::cout << "Make and model: " << automobile << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Was asking $" << a_price << std::endl;
    std::cout << "Now asking $" << d_price << std::endl;

    //do exact same thing using outFile instead of cout
    //All of there will be output ti File Io.txt
    outFlie << std::fixed;
    outFlie.precision(2);
    outFlie.setf(std::ios_base::showpoint);
    outFlie << "Make and model: " << automobile << std::endl;
    outFlie << "Year: " << year << std::endl;
    outFlie << "Was asking $" << a_price << std::endl;
    outFlie << "Now asking $" << d_price << std::endl;

    outFlie.close();

    return 0;
}