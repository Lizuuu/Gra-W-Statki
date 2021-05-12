#ifndef STATEK_H
#define STATEK_H

#ifndef STALE_H
#include "Stale.h"
#endif

#ifndef MAPA_H
#include "mapa.h"
#endif

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
class Mapa;

class Statek
{
public:
    Statek(int x1, int y1, int x2, int y2);
    bool czyZatopiony(Mapa *mapaKogo);    //sprawdza czy statek został w calosci zatopiony
    bool czyDodanyStatekKoliduje(int x1, int y1, int x2, int y2);
    Statek *getNastStatek();
    void setNastStatek(Statek *nastStatek);
    int getOrientacja();
    int getRozmiar();
    int getXPOCZ();
    int getYPOCZ();
    int getXKON();
    int getYKON();

private:
    int x_pocz,y_pocz,x_kon,y_kon;
    int orientacja;
    int rozmiar;
    Statek *nastStatek;
};

#endif // STATEK_H
