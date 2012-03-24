// Ponteiros: Vari�vel que armazena o endere�o de outra vari�vel
/*
Implementar uma fun��o que recebe dois par�metros (dois ponteiros para inteiros) e depois trocar o conte�do desses dois par�metros.
A assinatura da fun��o �: troca(int* p1, int* p2)
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

