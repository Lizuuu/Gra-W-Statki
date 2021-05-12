#ifndef ALGINTELIGENTNY_H
#define ALGINTELIGENTNY_H

#ifndef ALGORYTM_H
#include "algorytm.h"
#endif

#ifndef GRACZ_H
#include "gracz.h"
#endif

class Algorytm;

class AlgInteligentny : public Algorytm
{
public:
    AlgInteligentny();
    void wykonajAlgorytm(Mapa *mapaGracza, Gracz *gracz, Cpu *cpu);
    void zresetujAlgorytm();

private:
    int Xp,Yp,Xk,Yk;
    bool czyLosowac;
    bool kierunki [4];
};

#endif // ALGINTELIGENTNY_H
