#include "rozgrywka.h"

Rozgrywka::Rozgrywka()
{
    this->graczWygral=false;
    this->cpuWygral=false;
}

bool Rozgrywka::getCpuWygral()
{
    return cpuWygral;
}
bool Rozgrywka::getGraczWygral()
{
    return graczWygral;
}
bool Rozgrywka::getKolejGracza()
{
    return kolejGracza;
}
void Rozgrywka::setCpuWygral(bool y)
{
    cpuWygral=y;
}
void Rozgrywka::setGraczWygral(bool x)
{
    graczWygral=x;
}
void Rozgrywka::setKolejGracza(bool z)
{
    kolejGracza=z;
}

Mapa *Rozgrywka::udostepnijMapeGracza()
{
    return &mapaGracza;
}

Mapa *Rozgrywka::udostepnijMapeCPU()
{
    return &mapaCPU;
}
Cpu *Rozgrywka::udostepnijCPU()
{
    return &cpu;
}

Gracz *Rozgrywka::udostepnijGracza()
{
    return &gracz;
}

void Rozgrywka::resetRozgrywki()
{
    mapaGracza.zresetujMape();
    mapaCPU.zresetujMape();
    if(cpu.getAktualnyAlgorytm()!=NULL)
    {
        cpu.getAktualnyAlgorytm()->zresetujAlgorytm();
        cpu.deleteAktualnyAlgorytm();
        cout<<"DOKONANO RESETU ALGORYTMU"<<endl;
    }
    //RESET ODDANCYH STRZALOWCPU I ALGORYTMU
    graczWygral=false;
    cpuWygral=false;
    kolejGracza=true;
}
