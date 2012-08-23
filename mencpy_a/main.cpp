#include <iostream>
//#include <string.h>

void meancpy(char dest[], char orig[], int tamanhoOriginal){
    std::cout << "Array Original: " << orig << "\n";
    std::cout << "Array Destino: " << dest << "\n";

    for(int x = 0; x < tamanhoOriginal ; x++){

        std::cout << "Orig: " << x  << " " << orig[x] << "\n";
        dest[x] = orig[x];
        std::cout << "Dest: " << x  << " " << dest[x] << "\n\n";
    }

    std::cout << "Array Original: " << orig << "\n";
    std::cout << "Array Destino2: " << dest << "\n";

}

int main(){
    char orig[] = "UNOESC";
    char dest[7] = "";
    dest[6] = '\0';

    meancpy(dest,orig, 6);

    return 0;
}

