#include <iostream>
#include "Retangulo.h"


using namespace std;

int main()
{
    Retangulo retangulo;
    Ponto p1, p2, p3, p4;

    // Primeiro Ponto
    std::cout << "Primeiro ponto do Retangulo" << "\n";
    std::cout << "Digite a coordenada x: ";
    std::cin >> p1.x;
    std::cout << "Digite a coordenada y: ";
    std::cin >> p1.y;

    // Segundo Ponto
    std::cout << "Segundo ponto do Retangulo" << "\n";
    std::cout << "Digite a coordenada x: ";
    std::cin >> p2.x;
    cout << "Digite a coordenada y: ";
    std::cin >> p2.y;

    // Terceiro Ponto
    std::cout << "Terceiro ponto do Retangulo" << "\n";
    std::cout << "Digite a coordenada x: ";
    std::cin >> p3.x;
    std::cout << "Digite a coordenada y: ";
    std::cin >> p3.y;

    // Quarto Ponto
    std::cout << "Quarto ponto do Retangulo" << "\n";
    std::cout << "Digite a coordenada x: ";
    std::cin >> p4.x;
    std::cout << "Digite a coordenada y: ";
    std::cin >> p4.y;

    std:: cout << "\n\n";

    std::cout << "::Coordenadas Informadas::" << "\n";
    std::cout << "Primeiro Ponto: " << p1.x << "," << p1.y << "\n";
    std::cout << "Segundo Ponto: " << p2.x << "," << p2.y << "\n";
    std::cout << "Terceiro Ponto: " << p3.x << "," << p3.y << "\n";
    std::cout << "Quarto Ponto: " << p4.x << "," << p4.y << "\n\n";

    // Verificar se é um Retangulo
    bool teste = retangulo.verificarRetangulo(p1, p2, p3, p4);

    if (teste == 0)
    {
        std::cout << "Coordenadas nao formam um retangulo!"<< "\n";
    } else
    {
        // Imprimir
        std::cout << "Largura do Retangulo: " << retangulo.largura(p1,p2) << "\n";
        std::cout << "Altura do Retangulo: " << retangulo.altura(p1,p3) << "\n";
    }

    return 0;
}

