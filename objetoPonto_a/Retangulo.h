#include "Ponto.h"

class Retangulo{

public:
    bool set(Ponto pt1, Ponto pt2, Ponto pt3, Ponto pt4)
    {
        if((pt1.x == pt2.x) & (pt3.x == pt4.x) & (pt1.y == pt3.y) & (pt2.y == pt4.y ) & (pt1.y != pt3.y)){
           // p1.x = pt1.x;

            return true;

        }else{
            return false;
        }
    }

 private:
    Ponto p1, p2, p3, p4;


  public:
    int altura()
    {
        return p1.y - p3.y;

    }

    int largura()
    {
        return p1.x - p2.x;

    }
};
