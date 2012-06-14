#include <iostream>

void func(int* ponteiro){
    *ponteiro = 10;
    std::cout << "ponteiro: " << *ponteiro << "\n";
}

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
    int* ptr = new int;

    std::cout << "ptr endereco: " << *ptr << "\n";
    std::cout << "ptr endereco: " << ptr << "\n";

    * ptr = 5;

    std::cout << "*ptr: " << *ptr << "\n";

    func (ptr);

    delete ptr;

    std::cout << "ptr delete: " << *ptr << "\n";
    std::cout << "ptr delete: " << ptr << "\n";

    ptr = NULL;

    //*********************************************

    std::cout << "\n\nDigite o tamanho do vetor: ";
    int size =0;
    std::cin >> size;

    int * d_Array = new int[size];

    init(d_Array, size);

    return 0;
}

