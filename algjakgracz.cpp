#include "algjakgracz.h"

AlgJakGracz::AlgJakGracz()
{
    cout<<"algJakGracz"<<endl;
}

void AlgJakGracz::wykonajAlgorytm(Mapa *mapaGracza, Gracz *gracz, Cpu *cpu)
{
    int x,y;
    x = gracz->getXstrzal();
    y = gracz->getYstrzal();

    if(czyStrzalPoprawny(x,y))
    {
        oddaneStrzaly[y][x]='x';
        cpu->oddajStrzal(x,y,mapaGracza);
    }
    else
    {
        cout<<"BŁĄD ALGORYTMU JAK GRACZ"<<endl;
    }
}

void AlgJakGracz::zresetujAlgorytm()
{
    this->zresetujOddaneStrzaly();
}
