#include <iostream>


void init(int * ptr, int tamanho){
int x,y, temp;
int * origem = ptr; //ponteiro para guardar a posiçao inicial do ponteiro ptr

    for( x = 0; x < tamanho; x++){
        std::cout << "Digite um numero: ";
        std::cin >> temp;
        *ptr = temp;
        ptr++;
    }

    ptr = origem;

    for(y = 0; y < tamanho; y++){
        std::cout << "Ponteiro " << y  << ":" << *ptr << "\n";
        ptr++;
    }
}

int main()
{    
    std::cout << "Digite o tamanho do vetor: ";
    int size =0;
    std::cin >> size;

    int * d_Array = new int[size];

    init(d_Array, size);

    return 0;
}

