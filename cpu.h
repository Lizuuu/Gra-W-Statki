#ifndef CPU_H
#define CPU_H

#ifndef ALGORYTM_H
#include "algorytm.h"
#endif

#ifndef GRACZ_H
#include "gracz.h"
#endif

#include <ctime>

class Algorytm;

class Cpu : public Gracz
{
public:
    Cpu();
    bool rozmiescStatki(Mapa *mapaCpu, int *rozmiar);
    void setAktualnyAlgorytm(int nrAlgorytmu);
    Algorytm *getAktualnyAlgorytm();
    void deleteAktualnyAlgorytm ();

private:
    Algorytm *aktualnyAlgorytm;
};

#endif // CPU_H
