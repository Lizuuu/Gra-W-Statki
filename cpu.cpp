#include "cpu.h"
#include "alginteligentny.h"
#include "alglosowy.h"
#include "algjakgracz.h"

Cpu::Cpu()
{
    this->aktualnyAlgorytm=NULL;
}

bool Cpu::rozmiescStatki(Mapa *mapaCpu, int *rozmiar)
{
    srand(time(0));
    int licznik = rozmiar[0];
    cout << "licznik = "<<licznik<<endl;
    int i=1;
    int x1,y1,x2,y2,iloscLosowan = 0, orientacja;
    bool poprawnieWylosowany = false;
    while(i<=licznik)
    {
        cout<<"obrot nr"<<i-1<<endl;
        poprawnieWylosowany = false;
        iloscLosowan = 0;

        while(!poprawnieWylosowany /* && iloscLosowan++ < 1000*/)
        {
            x1=rand()%10;
            y1=rand()%10;
            cout << "x1y1 "<<x1<<  " "<< y1<<endl;
            if(rand()%2 == 0)
                orientacja = 0;     //pion
            else
                orientacja = 1;     //poziom

            cout << "orientacja: " << orientacja<<endl;
            if(orientacja==0)
            {
                y2=y1+rozmiar[i]-1;
                if(y2>9)        //sprawdzam punkt w dol mapy
                {
                    y2=y1-rozmiar[i]+1;
                    if(y2 < 0)  //sprawdzam punkt w gore mapy
                    {    poprawnieWylosowany=false;
                        cout << "statek nieutworzony mapa";
                    }
                    else    //tu sie tworzy statek w gore
                    {
                        if(!mapaCpu->dodajStatek(x1,y2,x1,y1))  //probuje tworzyc statek, jesli kolizja z innym zwraca losowanie nieprawidlowe
                        {

                            poprawnieWylosowany=false;
                            cout << "statek nieutworzony" << x1<<","<<y2<<","<< x1<<","<<y1<<endl;
                        }
                        else
                        {
                        poprawnieWylosowany=true;
                        cout << "statek utworzony" << x1<<","<<y2<<","<< x1<<","<<y1<<endl;
                        }

                    }
                }
                else    //tu sie tworzy statek w dol
                {
                    if(!mapaCpu->dodajStatek(x1,y1,x1,y2))  //probuje tworzyc statek, jesli kolizja z innym zwraca losowanie nieprawidlowe
                    {
                        poprawnieWylosowany=false;
                        cout << "statek nieutworzony" << x1<<","<<y1<<","<< x1<<","<<y2<<endl;
                    }
                    else
                    {
                    poprawnieWylosowany=true;
                    cout << "statek utworzony" << x1<<","<<y1<<","<< x1<<","<<y2<<endl;
                    }
                }

            }
            else
            {
                x2=x1+rozmiar[i]-1;
                if(x2>9)        //sprawdzam punkt w prawo mapy
                {
                    x2=x1-rozmiar[i]+1;
                    if(x2 < 0)  //sprawdzam punkt w lewo mapy
                    {
                        poprawnieWylosowany=false;
                        cout << "statek nieutworzony mapa";
                    }
                    else    //tu sie tworzy statek w lewo
                    {
                        if(!mapaCpu->dodajStatek(x2,y1,x1,y1))  //probuje tworzyc statek, jesli kolizja z innym zwraca losowanie nieprawidlowe
                        {
                            poprawnieWylosowany=false;
                            cout << "statek nieutworzony" << x2<<","<<y1<<","<< x1<<","<<y1<<endl;
                        }
                        else
                        {
                        poprawnieWylosowany=true;
                        cout << "statek utworzony" << x2<<","<<y1<<","<< x1<<","<<y1<<endl;
                        }

                    }
                }
                else    //tu sie tworzy statek w dol
                {
                    if(!mapaCpu->dodajStatek(x1,y1,x2,y1))  //probuje tworzyc statek, jesli kolizja z innym zwraca losowanie nieprawidlowe
                    {
                        poprawnieWylosowany=false;
                        cout << "statek nieutworzony" << x1<<","<<y1<<","<< x2<<","<<y1<<endl;
                    }
                    else
                    {
                    poprawnieWylosowany=true;
                    cout << "statek utworzony" << x1<<","<<y1<<","<< x2<<","<<y1<<endl;
                    }
                }
            }

        }
        i++;
    }

    if(iloscLosowan==1000)
    {
        return false;
    }
    return true;
}

void Cpu::setAktualnyAlgorytm(int nrAlgorytmu)
{
    if(nrAlgorytmu==ALGINT) //algorytm Inteligentny
    {
        this->aktualnyAlgorytm= new AlgInteligentny;
        cout<<"algorytm int"<<endl;
    }
    else if (nrAlgorytmu==ALGLOS) //algorytm Losowy
    {
        this->aktualnyAlgorytm= new AlgLosowy;
        cout<<"algorytm los"<<endl;
    }
    else if (nrAlgorytmu==ALGJAKGRACZ) //algorytm Jak Gracz
    {
        this->aktualnyAlgorytm= new AlgJakGracz;
        cout<<"algorytm jakgracz"<<endl;
    }
}

Algorytm *Cpu::getAktualnyAlgorytm()
{
    return this->aktualnyAlgorytm;
}

void Cpu::deleteAktualnyAlgorytm()
{
    if(this->aktualnyAlgorytm!=NULL)
    {
        delete this->aktualnyAlgorytm;
        this->aktualnyAlgorytm=NULL;
    }
}
