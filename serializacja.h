#ifndef SERIALIZACJA_H
#define SERIALIZACJA_H

#ifndef MAPA_H
#include "mapa.h"
#endif

#ifndef STATEK_H
#include "statek.h"
#endif

#ifndef GRACZ_H
#include "gracz.h"
#endif

#include <cstring>
#include <iostream>

using namespace std;

class Serializacja
{
public:
    Serializacja();

private :
    void zapiszDoPliku(string nazwaPliku);
    bool wczytajZPliku(string nazwaPliku);
};

#endif // SERIALIZACJA_H
