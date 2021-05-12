#ifndef ALGORYTM_H
#define ALGORYTM_H

#ifndef STALE_H
#include "Stale.h"
#endif

#ifndef MAPA_H
#include "mapa.h"
#endif

#ifndef GRACZ_H
#include "gracz.h"
#endif

#ifndef CPU_H
#include "cpu.h"
#endif

class Cpu;

class Algorytm
{
public:
    Algorytm();
    void zresetujOddaneStrzaly();
    char *getOddaneStrzaly();
    void setOddanyStrzal(int x, int y, char wartosc);
    bool czyStrzalPoprawny(int x, int y);
    virtual void wykonajAlgorytm(Mapa *mapaGracza, Gracz *gracz, Cpu *cpu)=0;
    virtual void zresetujAlgorytm()=0;

protected:
    char oddaneStrzaly[len][wid];
};

#endif // ALGORYTM_H
