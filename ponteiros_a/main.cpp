// Ponteiros: Variável que armazena o endereço de outra variável
/*
Implementar uma função que recebe dois parâmetros (dois ponteiros para inteiros) e depois trocar o conteúdo desses dois parâmetros.
A assinatura da função é: troca(int* p1, int* p2)
*/

#include <iostream>

void troca(int* p1, int* p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    int a = 10;
    int b = 20;    
    int* ponteiro_a = &a;
    int* ponteiro_b = &b;

    std::cout << "Variavel a: " << a << "\n";
    std::cout << "Variavel b: " << b << "\n";

    troca(ponteiro_a, ponteiro_b);

    std::cout << "Ponteiro da variavel a: " << *ponteiro_a << "\n";
    std::cout << "Ponteiro da variavel b: " << *ponteiro_b << "\n";

    return 0;
}

