#ifndef GRACZ_H
#define GRACZ_H

#ifndef MAPA_H
#include "mapa.h"
#endif

class Gracz
{
public:
    Gracz();
    void dodajPunktStatku(int X, int Y);
    void zapiszStrzalGracza(int X, int Y);
    bool sprawdzCzyFlotaGraczaZatopiona(Mapa *mapaGracza);
    bool sprawdzCzyTrafionyZatopiony(int x, int y,  Mapa *mapaGracza);
    bool sprawdzCzyTrafiony(int x, int y, Mapa *mapaGracza);
    bool oddajStrzal(int x, int y, Mapa *mapaPrzeciwnika);

    int getXstrzal();
    int getYstrzal();
    int getXwyborStatku();
    int getYwyborStatku();
    void setXwyborStatku(int x);
    void setYwyborStatku(int y);

private:
    int Xstrzal;
    int Ystrzal;
    int XwyborStatku;
    int YwyborStatku;
};

#endif // GRACZ_H
