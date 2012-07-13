#include "Ponto.h"

class Retangulo
{
public:
    // Verificar se as coordenadas informadas formão um retangulo
    bool verificarRetangulo (Ponto p1, Ponto p2, Ponto p3, Ponto p4)
    {
        if ((p1.x == p3.x) && (p2.x == p4.x )&& (p1.y == p2.y) && (p3.y == p4.y))
        {
            return true;
        }
        return false;
    }

    // Calcular Largura do Retangulo
    int largura(Ponto p1, Ponto p2)
    {
        return p2.x - p1.x;
    }

    // Calcular Altura do Retangulo
    int altura(Ponto p1, Ponto p3)
    {
        return p1.y - p3.y;
    }

private:
    Ponto p1;
    Ponto p2;
    Ponto p3;
    Ponto p4;
};
