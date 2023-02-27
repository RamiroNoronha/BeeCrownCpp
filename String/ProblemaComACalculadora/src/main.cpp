#include <iostream>
#include <list> 
#include <string>
int main() {
    unsigned long long int n;
    std::list<int> soma;
    std::cin >> n;

    for(int i =0; i < n; i++){
        std::string palavra = "";
        std::cin >> palavra;
        std::string palavra1 = palavra.substr(2, 2);
        std::string palavra2 = palavra.substr(5, 3);
        std::string palavra3 = palavra.substr(11);
        int n1 = std::stoi(palavra1);
        int n2 = std::stoi(palavra2);
        int n3 = std::stoi(palavra3);
        soma.push_back(n1+n2+n3);
    }

    for(auto itr = soma.begin(); itr !=  soma.end(); itr++){
        std::cout << *itr << std::endl;
    }
}