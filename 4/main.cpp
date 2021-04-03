#include <iostream>
#include <fstream>
#include <cstdlib>

bool sum_in_machinee(std::ifstream& cash_machin, int sum){
    int sum_in_machine=0, money;
    cash_machin.open("..\\cash_machine.bin");
    if (cash_machin.is_open()) {
        while (!cash_machin.eof()) {
            cash_machin >> money;
            sum_in_machine += money;
        }
        cash_machin.close();
    }
    if (sum > sum_in_machine) return false;
    return true;
}
int main() {
        char operation;
        bool check=false;
        int i=0, n, sum, sum_output=0;
        int money;
        int cash_machine[1000];
        std::ofstream cash_mach;
        std::ifstream cash_machin;

        std::cout << "Input operation:" << std::endl;
        std::cin >> operation;
        if (operation == '+') {
            cash_mach.open("..\\cash_machine.bin");
            cash_machin.open("..\\cash_machine.bin");
            while (i < 1000) {
                n = std::rand() % 4901 + 100;
                if (n == 100 || n == 500 || n == 1000 || n == 2000 || n == 5000) {
                    cash_machine[i] = n;
                    cash_machin >> money;
                    if (money != 0){
                        cash_machine[i] = money;
                    }
                    cash_mach << cash_machine[i] << std::endl;
                    i++;
                }
            }
            cash_machin.close();
            cash_mach.close();
        }
        if (operation == '-') {
            std::cout << "Input sum from 100 rub" << std::endl;
            std::cin >> sum;
            if (sum_in_machinee(cash_machin, sum)) {
                cash_machin.open("..\\cash_machine.bin");
                int j=0;
                while (!cash_machin.eof()) {
                    if (sum_output == sum) {
                        check = true;
                    }
                    cash_machin >> money;
                    sum_output += money;
                    cash_machine[j] = money;
                    if (sum_output > sum) {
                        sum_output -= money;
                    }
                    else {
                        cash_machine[j] = 0;
                    }
                    j++;
                }
                if (check){
                    std::cout << "Your " << sum_output << " RUB";
                }
            }
            else {
                std::cout << "not enough money"<<std::endl;
            }
            cash_machin.close();
            cash_mach.open("..\\cash_machine.bin");
            for (int j = 0; j < 1000; j++) {
                cash_mach << cash_machine[j] << std::endl;
            }
            cash_mach.close();
        }
}
