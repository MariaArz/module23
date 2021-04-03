#include <iostream>
#include <fstream>
#include <ctime>

int main() {
    std::srand(std::time(nullptr));
    std::ofstream pic("..\\pic.txt");
    int length, width;
    std::cout<<"Input parameters of picture\n";
    std::cin>>length>>width;
    for (int i=0; i<length; i++){
        for (int j=0; j < width; j++){
            pic << std::rand()%2;
        }
        pic << std::endl;
    }
    pic.close();
    return 0;
}
