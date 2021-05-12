#ifndef MAPA_H
#define MAPA_H

#ifndef STALE_H
#include "Stale.h"
#endif

#ifndef STATEK_H
#include "statek.h"
#endif

using namespace std;
class Statek;

class Mapa
{
public:
    Mapa();
    bool dodajStatek(int x1, int y1, int x2, int y2);
    char *getPola();
    void zresetujMape();
    void zaktualizujStatkiNaMapie(int x1,int y1, int x2, int y2);
    int *getParametryDlaCpu();
    void setPole(int x, int y, char wartosc);

    Statek *getStatkiPlywajace();   //lista statków wciaz plywajacych

private:
    char pola[len][wid];
    Statek *statkiPlywajace;
};

#endif // MAPA_H
