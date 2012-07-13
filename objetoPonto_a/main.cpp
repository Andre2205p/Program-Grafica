#include <iostream>
#include "Retangulo.h"

int main()
{
    Ponto p1, p2, p3, p4;
    //int p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y;
    Retangulo ret;

    std::cout << "Digite um valor para p1.x: ";
    std::cin >> p1.x;

    std::cout << "Digite um valor para p1.y: ";
    std::cin >> p1.y;

    std::cout << "Digite um valor para p2.x: ";
    std::cin >> p2.x;

    std::cout << "Digite um valor para p2.y: ";
    std::cin >> p2.y;

    std::cout << "Digite um valor para p3.x: ";
    std::cin >> p3.x;

    std::cout << "Digite um valor para p3.y: ";
    std::cin >> p3.y;

    std::cout << "Digite um valor para p4.x: ";
    std::cin >> p4.x;

    std::cout << "Digite um valor para p4.y: ";
    std::cin >> p4.y;


    if(ret.set(p1, p2, p3, p4) == true){
        std::cout << "E retangulo";
    }else{
        std::cout << "Nao e retangulo";
    }

    std::cout << "\nAltura: " << ret.altura();

    std::cout << "\nLargura: " << ret.largura() << "\n";

    return 0;
}
