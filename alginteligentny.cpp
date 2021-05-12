#include "alginteligentny.h"
#include "algorytm.h"

AlgInteligentny::AlgInteligentny()
{
    czyLosowac=true;
    kierunki[0]=true;
    kierunki[1]=false;
    kierunki[2]=false;
    kierunki[3]=false;
    Xp=-1;
    Xk=-1;
    Yp=-1;
    Yk=-1;
}

void AlgInteligentny::wykonajAlgorytm(Mapa *mapaGracza, Gracz *gracz, Cpu *cpu)
{
    bool trafiony;
    bool trafionyZatopiony;
    bool poprawnyStrzal;
    srand(time(0));
    int x,y;
    if(czyLosowac)
    {
        do
        {
        x = rand()%10;
        y = rand()%10;
        poprawnyStrzal=czyStrzalPoprawny(x,y);
        }while(!poprawnyStrzal);
        oddaneStrzaly[y][x]='x';

        cpu->oddajStrzal(x,y,mapaGracza);
        trafiony=gracz->sprawdzCzyTrafiony(x,y,mapaGracza);

        if(trafiony)
        {
            Xp = x;
            Xk = x;
            Yp = y;
            Yk = y;

            trafionyZatopiony = gracz->sprawdzCzyTrafionyZatopiony(x,y,mapaGracza);

            if(trafionyZatopiony)
            {
                Xp=-1;
                Xk=-1;
                Yp=-1;
                Yk=-1;
                kierunki[0]=true;
                kierunki[1]=false;
                kierunki[2]=false;
                kierunki[3]=false;
                czyLosowac=true;
            }
            else
            {
                czyLosowac=false;
            }
        }
        else
        {
            czyLosowac=true;
        }

    }
    else
    {
        if(kierunki[0]==true && Xk<9)  //Yk,Xk+1
        {
            x = Xk+1;
            y = Yk;
            poprawnyStrzal=czyStrzalPoprawny(x,y);
            if(!poprawnyStrzal)
            {
                kierunki [0]= false;
                kierunki[1]= true;
                czyLosowac=false;
                this->wykonajAlgorytm(mapaGracza, gracz, cpu);
            }
            oddaneStrzaly[y][x]='x';

            cpu->oddajStrzal(x,y,mapaGracza);
            trafiony=gracz->sprawdzCzyTrafiony(x,y,mapaGracza);

            trafionyZatopiony = gracz->sprawdzCzyTrafionyZatopiony(x,y,mapaGracza);

            if(trafiony)
            {
                Xk=Xk+1;

                if(trafionyZatopiony)
                {
                    Xp=-1;
                    Xk=-1;
                    Yp=-1;
                    Yk=-1;
                    kierunki[0]=true;
                    kierunki[1]=false;
                    kierunki[2]=false;
                    kierunki[3]=false;
                    czyLosowac=true;
                }
            }
            else
            {
                kierunki [0]= false;
                kierunki[1]= true;
                czyLosowac=false;
            }

        }
        else if(kierunki[1]==true && Xp>0)   //Yp,Xp-1
        {
            x = Xp-1;
            y = Yp;
            poprawnyStrzal=czyStrzalPoprawny(x,y);
            if(!poprawnyStrzal)
            {
                kierunki [1]= false;
                kierunki[2]= true;
                czyLosowac=false;
                this->wykonajAlgorytm(mapaGracza, gracz, cpu);
            }
            oddaneStrzaly[y][x]='x';

            cpu->oddajStrzal(x,y,mapaGracza);
            trafiony=gracz->sprawdzCzyTrafiony(x,y,mapaGracza);

            trafionyZatopiony = gracz->sprawdzCzyTrafionyZatopiony(x,y,mapaGracza);

            if(trafiony)
            {
                Xp=Xp-1;

                if(trafionyZatopiony)
                {
                    Xp=-1;
                    Xk=-1;
                    Yp=-1;
                    Yk=-1;
                    kierunki[0]=true;
                    kierunki[1]=false;
                    kierunki[2]=false;
                    kierunki[3]=false;
                    czyLosowac=true;
                }
            }
            else
            {
                kierunki [1]= false;
                kierunki[2]= true;
                czyLosowac=false;
            }

        }
        else if(kierunki[2]==true && Yk>0)  //Yk-1,Xk
        {
            x = Xk;
            y = Yk-1;
            poprawnyStrzal=czyStrzalPoprawny(x,y);
            if(!poprawnyStrzal)
            {
                kierunki [2]= false;
                kierunki[3]= true;
                czyLosowac=false;
                this->wykonajAlgorytm(mapaGracza, gracz, cpu);
            }
            oddaneStrzaly[y][x]='x';

            cpu->oddajStrzal(x,y,mapaGracza);
            trafiony=gracz->sprawdzCzyTrafiony(x,y,mapaGracza);

            trafionyZatopiony = gracz->sprawdzCzyTrafionyZatopiony(x,y,mapaGracza);

            if(trafiony)
            {
                Yk=Yk-1;

                if(trafionyZatopiony)
                {
                    Xp=-1;
                    Xk=-1;
                    Yp=-1;
                    Yk=-1;
                    kierunki[0]=true;
                    kierunki[1]=false;
                    kierunki[2]=false;
                    kierunki[3]=false;
                    czyLosowac=true;
                }
            }
            else
            {
                kierunki [2]= false;
                kierunki[3]= true;
                czyLosowac=false;
            }
        }
        else if(kierunki[3]==true && Yp<9)  //Yp+1,Xp
        {
            x = Xp;
            y = Yp+1;
            poprawnyStrzal=czyStrzalPoprawny(x,y);
            if(!poprawnyStrzal)
            {
                cout<<"NASTAPIL BLAD, ZRESTARTUJ GRE"<<endl;
            }
            oddaneStrzaly[y][x]='x';

            cpu->oddajStrzal(x,y,mapaGracza);
            trafiony=gracz->sprawdzCzyTrafiony(x,y,mapaGracza);

            trafionyZatopiony = gracz->sprawdzCzyTrafionyZatopiony(x,y,mapaGracza);

            if(trafiony)
            {
                Yp=Yp+1;

                if(trafionyZatopiony)
                {
                    Xp=-1;
                    Xk=-1;
                    Yp=-1;
                    Yk=-1;
                    kierunki[0]=true;
                    kierunki[1]=false;
                    kierunki[2]=false;
                    kierunki[3]=false;
                    czyLosowac=true;
                }
            }
            else
            {
                cout<<"BLAD OSTATNIEGO IFA KIERUNKU"<<endl;
            }
        }
        else if(Xk==9)
        {
            kierunki [0]= false;
            kierunki[1]= true;
            czyLosowac=false;
            this->wykonajAlgorytm(mapaGracza, gracz, cpu);
        }
        else if(Xp==0)
        {
            kierunki [1]= false;
            kierunki[2]= true;
            czyLosowac=false;
            this->wykonajAlgorytm(mapaGracza, gracz, cpu);
        }
        else if(Yk==0)
        {
            kierunki [2]= false;
            kierunki[3]= true;
            czyLosowac=false;
            this->wykonajAlgorytm(mapaGracza, gracz, cpu);
        }
        else if(Yp==9)
        {
            kierunki [3]= false;
            cout<<"BLAD DLA Yp=9"<<endl;
            czyLosowac=false;
            this->wykonajAlgorytm(mapaGracza, gracz, cpu);
        }
    }
}

void AlgInteligentny::zresetujAlgorytm()
{
    this->zresetujOddaneStrzaly();
    this->kierunki[0]=true;
    this->kierunki[1]=false;
    this->kierunki[2]=false;
    this->kierunki[3]=false;
    this->Xp= -1;
    this->Xk= -1;
    this->Yp= -1;
    this->Yk= -1;
    this->czyLosowac=true;
}
