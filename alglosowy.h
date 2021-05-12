#ifndef ALGLOSOWY_H
#define ALGLOSOWY_H

#ifndef ALGORYTM_H
#include "algorytm.h"
#endif

class AlgLosowy : public Algorytm
{
public:
    AlgLosowy();
    void wykonajAlgorytm(Mapa *mapaGracza, Gracz *gracz, Cpu *cpu);
    void zresetujAlgorytm();
};

#endif // ALGLOSOWY_H
