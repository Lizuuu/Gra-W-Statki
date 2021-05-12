#ifndef ALGJAKGRACZ_H
#define ALGJAKGRACZ_H

#ifndef GRACZ_H
#include "gracz.h"
#endif

#ifndef ALGORYTM_H
#include "algorytm.h"
#endif

#ifndef CPU_H
#include "cpu.h"
#endif

#ifndef ALGORYTMINTELIGENTNY_H
#include "alginteligentny.h"
#endif

#ifndef ALGORYTMLOSOWY_H
#include "alglosowy.h"
#endif

class AlgJakGracz : public Algorytm
{
public:
    AlgJakGracz();
    void wykonajAlgorytm(Mapa *mapaGracza, Gracz *gracz, Cpu *cpu);
    void zresetujAlgorytm();

private:
    int XGracza;
    int YGracza;
};

#endif // ALGJAKGRACZ_H
