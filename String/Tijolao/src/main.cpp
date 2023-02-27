#include <iostream>
#include <string>
#include <list>

std::string retornoMaiscula(int valor){
    if(valor >= 65 && valor <= 91){
        return "#";
    }
    return "";
}

std::string numeroLetra(int valor){
    int quantidade;
    std::string retorno = "";
    bool isMinuscula = (retornoMaiscula(valor) != "#");
    if((valor >=65 && valor <= 67) || (valor >=97 && valor <= 99)){
        if(isMinuscula){
            quantidade = valor - 97 +1;
        } else {
            quantidade = valor - 65 + 1;
        }
        for(int i =0; i < quantidade; i ++){
            retorno+='2';
        }          
    }
    if((valor >=68 && valor <= 70) || (valor >=100 && valor <= 102)){
        if(isMinuscula){
            quantidade = valor - 100 +1;
        } else {
            quantidade = valor - 68 + 1;
        }

        for(int i =0; i < quantidade; i ++){
            retorno+='3';
        }         
    }
    if((valor >=71 && valor <= 73) || (valor >=103 && valor <= 105)){
        if(isMinuscula){
            quantidade = valor - 103 +1;
        } else {
            quantidade = valor - 71 + 1;
        }

        for(int i =0; i < quantidade; i ++){
            retorno+='4';
        }          
    }
    if((valor >=74 && valor <= 76) || (valor >=106 && valor <= 108)){
        if(isMinuscula){
            quantidade = valor - 106 +1;
        } else {
            quantidade = valor - 74 + 1;
        }

        for(int i =0; i < quantidade; i ++){
            retorno+='5';
        }            
    }
    if((valor >=77 && valor <= 79) || (valor >=109 && valor <= 111)){
        if(isMinuscula){
            quantidade = valor - 109 +1;
        } else {
            quantidade = valor - 77 + 1;
        }

        for(int i =0; i < quantidade; i ++){
            retorno+='6';
        }            
    }
    if((valor >=80 && valor <= 83) || (valor >=112 && valor <= 115)){
        if(isMinuscula){
            quantidade = valor - 112 +1;
        } else {
            quantidade = valor - 80 + 1;
        }

        for(int i =0; i < quantidade; i ++){
            retorno+='7';
        }           
    }
    if((valor >=84 && valor <= 87) || (valor >=116 && valor <= 119)){
       if(isMinuscula){
            quantidade = valor - 116 +1;
        } else {
            quantidade = valor - 84 + 1;
        }

        for(int i =0; i < quantidade; i ++){
            retorno+='8';
        }           
    }
    if((valor >=88 && valor <= 91) || (valor >=119 && valor <= 122)){
        if(isMinuscula){
            quantidade = valor - 119 +1;
        } else {
            quantidade = valor - 88 + 1;
        }

        for(int i =0; i < quantidade; i ++){
            retorno+='9';
        }            
    }
    if(valor == 32){
        return "0";
    }
    return retorno;
}


int main() {
    // char letra = 'a';
    // int a = letra;
    // std::cout << a << std::endl;
    
    int n;
    std::list<std::string> palavras;
    std::cin >> n;
        for(int i =0; i < n; i++){
            std::string palavra; 
            //std::fflush(stdin);
            std::getline(std::cin, palavra);
            if(palavra == "\n" || palavra == ""){
                i--;
            }else{
                palavras.push_back(palavra);
            }
            
        }
        for(auto itr = palavras.begin(); itr != palavras.end(); itr++){
            std::string palavra = *itr;
            std::string output = "";
            std::string acrescimo;
            for(char letra : palavra){
                if(letra == '\n')
                    continue;
                int ascii = letra;
                output+=retornoMaiscula(ascii);
                acrescimo = numeroLetra(ascii);
                if(acrescimo[acrescimo.length() -1] == output[output.length() -1]){
                    output+= '*';
                }
                output+= acrescimo;
            }

            std::cout << output << std::endl;
        }
        palavras.clear();
    
}