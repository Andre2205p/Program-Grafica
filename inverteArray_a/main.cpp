#include <iostream>
#include <strings.h>

char * inverte(char* str){
    int tamanho = strlen(str);
    char* inv_str = new char[tamanho+1];
    int x, j;

    for (x=0,j=tamanho - 1;x < tamanho; x++, j--  )
    {
        inv_str[j] = str[x];
    // std::cout << str[x];
    }
    //std::cout <<"\n";
    inv_str [tamanho] = '\0';

    return inv_str;
}


int main()
{
    char msg[] = "Andre_G._da_Silva";
    char* invertido = inverte(msg);
    std::cout << invertido << "\n";

    return 0;
}

