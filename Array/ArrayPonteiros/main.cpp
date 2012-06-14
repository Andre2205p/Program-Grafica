#include <iostream>


int main()
{
    int vetor[]={1,2,3,4,5,6,7,8,9}, * ptr, x =0;
    ptr = vetor;
/*
    while(*ptr < sizeof(vetor)){
        std::cout << "valor de *ptr: " << *ptr << "\n";
        ptr++;
    }
*/

    for(x = 0; x < sizeof(vetor)/ sizeof(int); x++){ // divide o tamanho do vetor (sizeof(vetor) pelo
                                                     // tamanho do tipo da varável (sizeof(int))
        std::cout << "valor de *ptr: " <<* ptr << "\n";
        ptr++;
    }


    return 0;
}

