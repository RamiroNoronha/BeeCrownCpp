#include <iostream>
#include <math.h>
int size(int n){
    int s = 0;
    for(int i = 1; ; i*=10){
        if(n/i > 0){
            s++;
        } else {

            return s;
        }
    }
    
}

int factorial(int f){
    if(f == 0){
        return 1;
    }
    if(f == 1){
        return 1;
    }
    int factorialValue = 1;
    for(int i = 2; i <= f; i++){
        factorialValue*=i;
    }

    return factorialValue;
}

int digitDecimalValue(int n, int f){

    return n * factorial(f);
}

int separatedDigit(int n, int p, int valueBefore){
    int divisor = std::pow(10, p );
    int value = n - valueBefore;
    int digit = (value % divisor) / std::pow(10, p-1);

    return digit;
}



int main() {
    int n;
    while(std::cin >> n){
        // Esse caso foi adicionado por causa do beeCrown
        if(n == 0){
            break;
        }
        int s = size(n);
        int valueBefore =0;
        int decimal = 0;
        int currentDigit;
        for(int i =1; i <=s; i++){
            currentDigit=separatedDigit(n, i, valueBefore);
            valueBefore+= currentDigit * std::pow(1, i);
            decimal+=digitDecimalValue(currentDigit, i);
        }
        std::cout << decimal << std::endl;
    }
}