#include "alglosowy.h"

AlgLosowy::AlgLosowy()
{
    cout<<"alglosowy"<<endl;
}

void AlgLosowy::wykonajAlgorytm(Mapa *mapaGracza, Gracz *gracz, Cpu *cpu)
{
    srand(time(0));
    int x,y;
    do
    {
    x = rand()%10;
    y = rand()%10;
    }while(!czyStrzalPoprawny(x,y));

    oddaneStrzaly[y][x]='x';

    cpu->oddajStrzal(x,y,mapaGracza);
}

void AlgLosowy::zresetujAlgorytm()
{
    this->zresetujOddaneStrzaly();
}
