#include<iostream>
#include<string>

int main(){
    int quantidade;
    std::cin >> quantidade;

    int* vi;
    int* vf;
    vi = new int[quantidade];
    vf = new int[quantidade];
    std::string* espelhos;
    espelhos = new std::string[quantidade];

    for(int i =0; i < quantidade; i++){
        std::cin >> vi[i];
        std::cin >> vf[i];
    }
    
    for(int i =0; i < quantidade; i++){
        espelhos[i] = "";
        for(int j = vi[i]; j <= vf[i]; j++){
            espelhos[i]+=std::to_string(j);
        }
        for(int j = vf[i]; j>= vi[i]; j--){
            std::string ordenado, inverso = "";
            ordenado = std::to_string(j);
            for(int k = ordenado.size() -1; k >= 0; k--){
                inverso+=ordenado[k];
            }
            espelhos[i]+=inverso;
        }
        
    }
    
    for(int i =0; i < quantidade; i++){
        std::cout << espelhos[i] << std::endl;
    }
    delete[] vi, vf, espelhos;
    
    return 0;
}