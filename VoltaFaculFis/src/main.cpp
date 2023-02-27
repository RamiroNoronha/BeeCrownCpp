#include<iostream>
#include<math.h>

int main(){
    int v, t;
    double a;
    double space;
    while(std::cin >> v){
        std::cin >> t;
        if(t != 0){
        a = (v * 1.0)/ t;
        space = (a * t * t  * 4)/2.0;
        
        } else {
            space = 0;
        }
        std::cout << space << std::endl;
        
    }
    

}