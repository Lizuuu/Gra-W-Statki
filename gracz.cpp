#include "gracz.h"

Gracz::Gracz()
{

}

void Gracz::dodajPunktStatku(int X, int Y)
{
    this->XwyborStatku=X;
    this->YwyborStatku=Y;
}

void Gracz::zapiszStrzalGracza(int X, int Y)
{
    this->Xstrzal=X;
    this->Ystrzal=Y;
}

int Gracz::getXstrzal()
{
    return this->Xstrzal;
}

int Gracz::getYstrzal()
{
    return this->Ystrzal;
}

int Gracz::getXwyborStatku()
{
    return this->XwyborStatku;
}

int Gracz::getYwyborStatku()
{
    return this->YwyborStatku;
}

bool Gracz::sprawdzCzyFlotaGraczaZatopiona(Mapa *mapaGracza)
{
    int iloscStatkow=0;
    Statek *akt = mapaGracza->getStatkiPlywajace();
    while(akt!=NULL)
    {
        iloscStatkow++;
        akt=akt->getNastStatek();
    }
    akt = mapaGracza->getStatkiPlywajace();
    int ileStatkowZatopionych=0;
    while(akt!=NULL)
    {
        if(akt->czyZatopiony(mapaGracza))
        {
            ileStatkowZatopionych++;
        }
        akt=akt->getNastStatek();
    }

    cout<<"iloscStatkow = "<<iloscStatkow<<endl<<"ileStatkoZatopionych = "<<ileStatkowZatopionych<<endl;

    if(ileStatkowZatopionych==iloscStatkow)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Gracz::sprawdzCzyTrafionyZatopiony(int x, int y, Mapa *mapaGracza)
{
    Statek *akt=mapaGracza->getStatkiPlywajace();
    while(akt!=NULL)
    {
        if(akt->getOrientacja()==0)      //pion
        {
            for(int i=akt->getYPOCZ();i<=akt->getYKON();i++)
            {
                if(x==akt->getXPOCZ() && y==i)
                {
                    if(akt->czyZatopiony(mapaGracza))
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        else    //poziom
        {
            for(int i=akt->getXPOCZ();i<=akt->getXKON();i++)
            {
                if(x==i && y==akt->getYPOCZ())
                {
                    if(akt->czyZatopiony(mapaGracza))
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        akt=akt->getNastStatek();
    }
}

bool Gracz::oddajStrzal(int x, int y, Mapa *mapaPrzeciwnika)
{
    char *polaGracza = mapaPrzeciwnika->getPola();
    if(*((polaGracza+y*len)+x)=='w')
    {
        *((polaGracza+y*len)+x)='n';
        return true;
    }
    else if(*((polaGracza+y*len)+x)=='s')
    {
        *((polaGracza+y*len)+x)='x';
        return true;
    }
    else
    {
        return false;
    }
}

bool Gracz::sprawdzCzyTrafiony(int x, int y, Mapa *mapaGracza)
{
    char *polaGracza = mapaGracza->getPola();
    if(*((polaGracza+y*len)+x)=='x')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Gracz::setXwyborStatku(int x)
{
    this->XwyborStatku=x;
}

void Gracz::setYwyborStatku(int y)
{
    this->YwyborStatku=y;
}
