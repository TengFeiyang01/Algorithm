//#include <iostream>
//
//int main() {
//    const int MAXSIZE = 20;
//    char name[MAXSIZE];
//    char dessert[MAXSIZE];
//
//    std::cout << "Enter your name: \n";
//    //getline每次读取一行，但不保存换行符 而是使用"\0"代替
//    std::cin.getline(name, MAXSIZE);
//    std::cout << "Enter your favorite dessert:\n";
//    std::cin.getline(dessert, MAXSIZE);
//    std::cout << "I have your delicious " << dessert;
//    std::cout << " for you, " << name << ".\n";
//    //等价
//    //std::cin.getline(name, MAXSIZE).getline(dessert, MAXSIZE);
//
//
//    //std::cin.get(name, MAXSIZE).get();  //读取第一行，其后的get会读取换行符
//
//
//    return 0;
//}