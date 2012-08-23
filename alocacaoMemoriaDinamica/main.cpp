#include <iostream>

void func(int* ponteiro){
    *ponteiro = 10;
    std::cout << "ponteiro: " << *ponteiro << "\n";
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

    return 0;
}

