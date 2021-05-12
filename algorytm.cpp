#include "algorytm.h"

Algorytm::Algorytm()
{
    zresetujOddaneStrzaly();
}

void Algorytm::zresetujOddaneStrzaly()
{
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<wid;j++)
        {
            oddaneStrzaly[i][j]='n';        //n - brak strzalu w dane pole
        }
    }
}

char *Algorytm::getOddaneStrzaly()
{
    return *oddaneStrzaly;
}

void Algorytm::setOddanyStrzal(int x, int y, char wartosc)
{
    oddaneStrzaly[x][y]=wartosc;
}

bool Algorytm::czyStrzalPoprawny(int x, int y)
{
    if(oddaneStrzaly[y][x]=='n')
    {
        return true;
    }
    else
    {
        return false;
    }
}
