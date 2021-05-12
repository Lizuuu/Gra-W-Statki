#include "statek.h"

Statek::Statek(int x1, int y1, int x2, int y2)
{
    if(x1==x2)
    {
        orientacja=0;
        rozmiar = y2-y1+1;
    }
    else if(y1==y2)
    {
        orientacja=1;
        rozmiar = x2-x1+1;
    }
    if(x1<=x2)
    {
        this->x_pocz=x1;
        this->x_kon=x2;
    }
    else
    {
        this->x_pocz=x2;
        this->x_kon=x1;
    }
    if(y1<=y2)
    {
        this->y_pocz=y1;
        this->y_kon=y2;
    }
    else
    {
        this->y_pocz=y2;
        this->y_kon=y1;
    }
}

bool Statek::czyZatopiony(Mapa *mapaKogo)
{
    char *pola = mapaKogo->getPola();
    int licznikPion = 0;
    int licznikPoziom = 0;
    int x1,x2,y1,y2;
    if(x_kon>x_pocz)
    {
       x1=x_pocz;
       x2=x_kon;
    }
    else
    {
        x1=x_kon;
        x2=x_pocz;
    }
    if(y_kon>y_pocz)
    {
        y1=y_pocz;
        y2=y_kon;
    }
    else
    {
        y1=y_kon;
        y2=y_pocz;
    }
    if(orientacja==0)           //pion
    {
        for(int i=y1;i<=y2;i++)
        {
            if(*((pola+i*len)+x1)=='x')
                licznikPion++;
        }
        if(licznikPion==rozmiar)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(orientacja==1)       //poziom
    {
        for(int i=x1;i<=x2;i++)
        {
            if(*((pola+y1*len)+i)=='x')
                licznikPoziom++;
        }
        if(licznikPoziom==rozmiar)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Statek::czyDodanyStatekKoliduje(int x1, int y1, int x2, int y2)
{
    char **kolizjeStatku = new char *[len];
    for(int i=0;i<len;i++)
    {
        kolizjeStatku[i]=new  char[wid];
    }

    for(int i=0;i<len;i++)
    {
        for(int j=0;j<wid;j++)
        {
            kolizjeStatku[i][j]='w';
        }
    }

    if(orientacja==1)       //poziom
    {
        for(int i=x_pocz;i<=x_kon;i++)
        {
            kolizjeStatku[y_pocz][i]='s';
            if(y_pocz>0)
                kolizjeStatku[y_pocz-1][i]='s';
            if(y_pocz<9)
                kolizjeStatku[y_kon+1][i]='s';
        }
        if(x_pocz>0)
            kolizjeStatku[y_pocz][x_pocz-1]='s';
        if(x_kon<9)
            kolizjeStatku[y_pocz][x_kon+1]='s';
    }
    else if(orientacja==0)       //pion
    {
        for(int i=y_pocz;i<=y_kon;i++)
        {
            kolizjeStatku[i][x_pocz]='s';
            if(x_pocz>0)
                kolizjeStatku[i][x_pocz-1]='s';
            if(x_kon<9)
                kolizjeStatku[i][x_kon+1]='s';
        }
        if(y_pocz>0)
            kolizjeStatku[y_pocz-1][x_pocz]='s';
        if(y_kon<9)
            kolizjeStatku[y_kon+1][x_pocz]='s';
    }

    for(int i=0;i<len;i++)
    {
        for(int j=0;j<wid;j++)
        {
            cout<<kolizjeStatku[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    int licznik=0;

    if(x1==x2)
    {
        for(int i=y1;i<=y2;i++)
        {
            if(kolizjeStatku[i][x1]=='s')
                licznik++;
        }
    }
    if(y1==y2)
    {
        for(int i=x1;i<=x2;i++)
        {
            if(kolizjeStatku[y1][i]=='s')
                licznik++;
        }
    }
    if(licznik==0)
    {
        return false;
    }
    else
    {
        return true;
    }

    for(int i=0;i<len;i++)
    {
        delete [] kolizjeStatku[i];
    }
    delete [] kolizjeStatku;
    kolizjeStatku=NULL;
}

Statek *Statek::getNastStatek()
{
    return nastStatek;
}

void Statek::setNastStatek(Statek *nastStatek)
{
    this->nastStatek = nastStatek;
}

int Statek::getRozmiar()
{
    return rozmiar;
}

int Statek::getXPOCZ()
{
    return this->x_pocz;
}

int Statek::getYPOCZ()
{
    return this->y_pocz;
}

int Statek::getXKON()
{
    return this->x_kon;
}

int Statek::getYKON()
{
    return this->y_kon;
}

int Statek::getOrientacja()
{
    return this->orientacja;
}
