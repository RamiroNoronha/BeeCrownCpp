#include <iostream>
#include <string>

int main(){
    std::string a;
    int n, k;
    unsigned long long int fat;
    std::cin >> n;
    unsigned long long int* p;
    p = new unsigned long long int[n];
    for(int i =0; i < n; i++){
        std::cin >> a;
        
        k = 0;
        for(int j =0; j < a.length(); j++){
            if(a[j] == '!'){
                k++;
            }
        }
        fat = 1;
        for(int l = std::stoi(a); l >=1; l-=k){
            fat *= l;
        }
        p[i] = fat;
    }
    for(int i =0; i < n; i++){
        std::cout << p[i] << std::endl;
    }
    delete[] p;
    
}