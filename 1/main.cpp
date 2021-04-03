#include <iostream>
#include <fstream>
#include <string>
int main() {
    std::string name, soname, date;
    double money;
    std::ofstream pay_list("..\\pay_list.txt", std::ios::app);

    std::cout<<"Input new person:\n";
    std::cin>>name >> soname >> date >> money;

    if ((std::stoi(date.substr(6)) < 0 || std::stoi(date.substr(6)) > 2021)
        || (std::stoi(date.substr(3,2)) < 0 || std::stoi(date.substr(3,2)) > 12)
        || (std::stoi(date.substr(0,2)) < 0 || std::stoi(date.substr(0,2)) > 32)
        || ((std::stoi(date.substr(3,2)) == 02
        && (std::stoi(date.substr(0,2)) < 0 || std::stoi(date.substr(0,2)) > 29)))){

        std::cout<<"Error"<< std::endl;
    }
    else pay_list << name << " " << soname << " " << date << " " << money << std::endl;
    pay_list.close();
}
