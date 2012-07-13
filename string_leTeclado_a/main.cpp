#include <iostream>
#include <string.h>

int main(){
std::string nome = "Andre";
std::cout << "Meu nome e: " << nome << "\n";

    char nome_array[50];
 //    nome_array = (char*)nome.c_str();

//nome_array = nome.c_str();
// .c_str() retorna um const (contante)

    nome = nome_array;

    std::cin >> nome;
    nome += "Goncalves";
    std::cout << nome << "\n";
    std::cout << nome.length();

    return 0;
}

