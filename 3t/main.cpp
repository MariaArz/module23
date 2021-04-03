#include <iostream>
#include <fstream>

int main() {
    int count=0;
    std::cout << "Input fish"<<std::endl;
    std::string fish, fishinriver;
    std::cin>>fish;
    std::ifstream river;
    river.open("..\\river.txt");
    if (river.is_open()){
        while (!river.eof()){
            river >> fishinriver;
            if (fishinriver == fish){
                std::ofstream basket("..\\basket.txt", std::ios::app);
                basket << fish << std::endl;
                count++;
                basket.close();
            }
        }
        std::cout<<"\nThis fishing have " << count <<" fish";
    }
    else std::cout<<"file is not open";
    river.close();
    return 0;
}
