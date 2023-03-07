#include <iostream>
#include <math.h>
long long int result(int number, int i, int j){
    long long int result = 1;
    if(i>=j){
        for(int k = number; k >i; k--){
            result*=k;
        }
        for(int l = j; l > 0; l--){
            result/=l;
        }
    } else {
       for(int k = number; k >j; k--){
            result*=k;
        }
        for(int l = i; l > 0; l--){
            result/=l;
        }
    }
    return result;
}

int main() {
    int n;
    while(std::cin >> n){

    if(n ==0) break;
    long long int accumulator = 0;
    int j =0;
    for(int i = n; j<= n/2; i-=2){
        long long int receiver = result(i+j, i, j);     
        accumulator += receiver;
        j+=1;
    }

    std::cout << accumulator << std::endl;
    }
    
    
    return 0;
}
