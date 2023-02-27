#include<iostream>
#include<string>

    int getTimes(char letter){
        switch (std::tolower(letter))
        {
        case 'a':
        case 'd':
        case 'g':
        case 'j':
        case 'm':
        case 'p':
        case 't':
        case 'w':
        case '1':
        case ' ':
            return 1;
        case 'b':
        case 'e':
        case 'h':
        case 'k':
        case 'n':
        case 'q':
        case 'u':
        case 'x':
        case '0':
            return 2;
        case 'c':
        case 'f':
        case 'i':
        case 'l':
        case 'o':
        case 'r':
        case 'v':
        case 'y':
            return 3;
        case 's':
        case 'z':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':      
        case '8':
            return 4;
        case '7':
        case '9':
            return 5;
        default:
            return 3;
        }
    }

    char getKeyBoard(char letter){
        switch (std::tolower(letter))
        {
        case '1':
            return '1';
        case 'a':
        case 'b':
        case 'c':
        case '2':
            return '2';
        case 'd':
        case 'e':
        case 'f':
        case '3':
            return '3';
        case 'g':
        case 'h':
        case 'i':
        case '4':
            return '4';
        case 'j':
        case 'k':
        case 'l':
        case '5':
            return '5';
        case 'm':
        case 'n':
        case 'o':
        case '6':
            return '6';
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case '7':
            return '7';
        case 't':
        case 'u':
        case 'v':
        case '8':
            return '8';
        case 'w':
        case 'x':
        case 'y':
        case 'z':
        case '9':
            return '9';       
        default:
            return '0';
        }
        return '0';
    }

int main(){
    int n;
    std::string phrase, output;
    std::cin >> n;
    std::cin.ignore();
    char letter, key, olderKey = '.';
    while(n--){
        output = "";
        std::getline(std::cin, phrase);
        for(auto itr = phrase.begin(); itr != phrase.end(); itr++){
            letter = *itr;
            if(letter == '\n')
                continue;
            key = getKeyBoard(letter);
            if(letter >=65 && letter <=90){
                output+="#";
            } else if(key == olderKey){
                output+="*";
            }
            int times = getTimes(letter);
            while(times--){
                output+=key;
            }
            olderKey = key;         
        }

        std::cout << output << std::endl;
    }

    return 0;
}