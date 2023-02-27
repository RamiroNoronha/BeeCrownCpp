#include <iostream>

int main() {
    int b, t;
    int h = 70, l = 160;
    
    int area = h* l;
    float percent;
    while(std::cin >> b){
        std::cin >> t;
        float felix = (b+t) * h /2.F;
        percent = felix/area;
        if(percent > 0.5F){
            std::cout << 1 << std::endl;
        } else if (percent < 0.5F){
            std::cout << 2 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }
}