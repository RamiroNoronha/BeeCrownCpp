#include <iostream>
int main() {
    int n;
    std::cin >> n;
    while(n!=0){
    unsigned long long int quantidade = n * ( n+ 1 ) * (2*n +1 )/6;
    // for(int i =n; i > 0; i--){
    //     quantidade+= pow((n-i+1), 2);
    // }
    std::cout << quantidade << std::endl;
    std::cin >> n;

    }
    
}