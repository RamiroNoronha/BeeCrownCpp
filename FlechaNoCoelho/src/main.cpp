#include <iostream>
#include <math.h>
#include <iomanip>
int main() {
    double d, a, r;
    double pi = 3.14159265359;
    while(std::cin >> a){
        std::cin >> d;
        std::cin >> r;
        double degres = (r - 90.0) * (pi /180.0);
        double h;
        if(degres > 0){
             h = a + d * std::tan(degres);
        } else {
            h = a - d * std::tan(-degres);
        }
        std::cout << std::fixed << std::setprecision(4);
        std::cout << h << std::endl;
    }
}