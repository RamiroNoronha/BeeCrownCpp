#include <iostream>
#include <string>
#include <list>
int main() {
    int n;
    std::list<std::string> codigos;
    while(std::cin >> n){
        for(int i =0; i < n; i++){
        std::string codigo;
        std::cin >> codigo;
        codigos.push_back(codigo);
        }
        codigos.sort();
        for(auto itr = codigos.begin(); itr != codigos.end(); itr++){
            std::cout << *itr << std::endl;
        }
        codigos.clear();
    }
    
    
}