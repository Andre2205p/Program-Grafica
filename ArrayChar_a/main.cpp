#include <iostream>
#include <strings.h>

int strlen(char str []){

    int tam = 0;
    for(int x = 0; str[x] != '\0' ; x++ ){

        tam ++;
    }
    return tam;
}

int main()
{
    char array[] = "UNOESC";
    std::string nome = "Andre";

    //char nome_array[50];
    //nome_array = nome.c_str();

    std::cout << "Meu nome e: "<< nome << "\n";
    std::cout << "O numero de caracteres da UNOESC e: " << strlen(array) << "\n";

    return 0;
}
