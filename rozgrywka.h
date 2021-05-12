#ifndef ROZGRYWKA_H
#define ROZGRYWKA_H

#ifndef MAPA_H
#include "mapa.h"
#endif

#ifndef GRACZ_H
#include "gracz.h"
#endif

#ifndef CPU_H
#include "cpu.h"
#endif

class Rozgrywka
{
public:
    int stanGry;
    int x_pocz_tmp, y_pocz_tmp;

    Rozgrywka();
    void resetRozgrywki();
    bool getGraczWygral();
    bool getCpuWygral();
    bool getKolejGracza();
    void setGraczWygral(bool x);
    void setCpuWygral(bool y);
    void setKolejGracza(bool z);

    Mapa *udostepnijMapeGracza();
    Mapa *udostepnijMapeCPU();
    Cpu *udostepnijCPU();
    Gracz *udostepnijGracza();

private:
    Mapa mapaGracza;
    Mapa mapaCPU;
    Cpu cpu;
    Gracz gracz;
    bool graczWygral;
    bool cpuWygral;
    bool kolejGracza;

};

#endif // ROZGRYWKA_H
