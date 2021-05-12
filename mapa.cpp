#include "mapa.h"

Mapa::Mapa()
{
    this->statkiPlywajace=NULL;
}

bool Mapa::dodajStatek(int x1, int y1, int x2, int y2)
{
    Statek *wskaznik = getStatkiPlywajace();

    while(wskaznik != NULL)
    {
        if(wskaznik->czyDodanyStatekKoliduje(x1, y1, x2, y2))
        {
            return false;
        }

        wskaznik = wskaznik->getNastStatek();
    }

    Statek *tmp = new Statek(x1,y1,x2,y2);
    tmp->setNastStatek(statkiPlywajace);
    statkiPlywajace = tmp;

    zaktualizujStatkiNaMapie(x1,y1,x2,y2);

    return true;

}

char *Mapa::getPola()
{
    return *pola;
}

Statek *Mapa::getStatkiPlywajace()
{
    return this->statkiPlywajace;
}

void Mapa::zresetujMape()           //ZROBIĆ TUTAJ CAŁKOWITY RESET (DELETE STATKI, PARAMETRY DLA CPU ITP)
{
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<wid;j++)
        {
            pola[i][j]='w';
        }
    }
    Statek *akt;
    Statek *tmp;
    akt = getStatkiPlywajace();
    while(akt!=NULL)
    {
        tmp=akt;
        akt=akt->getNastStatek();
        delete tmp;
    }
    this->statkiPlywajace=NULL;
}

void Mapa::zaktualizujStatkiNaMapie(int x1, int y1, int x2, int y2)
{
    if(x1==x2)
    {
        for(int i=y1;i<=y2;i++)
        {
            pola[i][x1]='s';
        }
    }
    if(y1==y2)
    {
        for(int i=x1;i<=x2;i++)
        {
            pola[y1][i]='s';
        }
    }
}

void Mapa::setPole(int x, int y, char wartosc)
{
    pola[x][y]=wartosc;
}

int *Mapa::getParametryDlaCpu()
{
    Statek *akt = statkiPlywajace;
    int licznik = 0;
    while(akt!=NULL)
    {
        licznik++;
        akt=akt->getNastStatek();
    }

    int *parametryDlaCpu;
    parametryDlaCpu = new int[licznik+1];
    parametryDlaCpu[0]=licznik;

    int i=1;
    akt=statkiPlywajace;

    while(akt!=NULL)
    {
        parametryDlaCpu[i]=akt->getRozmiar();
        i++;
        akt=akt->getNastStatek();
    }

    return parametryDlaCpu;
}
