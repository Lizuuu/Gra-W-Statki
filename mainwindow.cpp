#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene_p = new QGraphicsScene(this);
    ui->player->setScene(scene_p);
    scene_cpu= new QGraphicsScene(this);
    ui->cpu->setScene(scene_cpu);

    this->GUI.skonfigurujGUI(scene_p,scene_cpu);

    ui->algorytm->addItem("Algorytm Inteligentny");
    ui->algorytm->addItem("Algorytm Losowy");
    ui->algorytm->addItem("Algorytm Jak Gracz");

    ui->rozpocznij_gre->setEnabled(false);
    ui->zapisz->setEnabled(false);
    ui->resetuj->setEnabled(true);
    rozgrywka.stanGry=STAN_START;
    ui->label->setText("");
    ui->pole_tekst->setVisible(false);
    ui->enter->setVisible(false);
    ui->pole_tekst_wczyt->setVisible(false);
    ui->enter_wczyt->setVisible(false);
    ui->label->setText("   ABY ROZPOCZĄĆ GRĘ, WCIŚNIJ PRZYCISK KONFIGURUJ GRĘ");
}

void MainWindow::wczytajPunktKlikniecia(int Xmyszki, int Ymyszki)
{
   int x_pom = Xmyszki-11;
   int y_pom = Ymyszki-11;
   int m = x_pom%SQUARE;
   int n = y_pom%SQUARE;
   int x,y;
   if(m==0)
   {
    x=x_pom/SQUARE-1;
   }
   else
   {
       x=(x_pom-m)/SQUARE-1;
   }
   if(n==0)
   {
       y=y_pom/SQUARE-1;
   }
   else
   {
       y=(y_pom-n)/SQUARE-1;
   }
   if(rozgrywka.stanGry==1 || rozgrywka.stanGry==2)
   {
       rozgrywka.udostepnijGracza()->dodajPunktStatku(x,y);
   }
   else if (rozgrywka.stanGry==3)
   {
       x=x-20;
       rozgrywka.udostepnijGracza()->zapiszStrzalGracza(x,y);
   }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    bool kolizja=false;
    QBrush redBrush (Qt::red);
    QPen blackPen (Qt::black);

    if(event->button() == Qt::LeftButton)
    {
        //GUI.aktualizujGUI(rozgrywka,kwadrat,scene_p,scene_cpu);
        if(rozgrywka.stanGry==3)
        {
            QPointF mousePoint = ui->cpu->mapToScene(event->pos());
            wczytajPunktKlikniecia(mousePoint.rx(),mousePoint.ry());
            cout<<"x= "<<rozgrywka.udostepnijGracza()->getXstrzal()<<" y= "<<rozgrywka.udostepnijGracza()->getYstrzal()<<endl;
        }
        else
        {
            QPointF mousePoint = ui->player->mapToScene(event->pos());
            wczytajPunktKlikniecia(mousePoint.rx(),mousePoint.ry());
            cout<<"x= "<<rozgrywka.udostepnijGracza()->getXwyborStatku()<<" y= "<<rozgrywka.udostepnijGracza()->getYwyborStatku()<<endl;
        }

        if(rozgrywka.udostepnijGracza()->getXwyborStatku()>=0 && rozgrywka.udostepnijGracza()->getXwyborStatku()<=9 && rozgrywka.udostepnijGracza()->getYwyborStatku()>=0 && rozgrywka.udostepnijGracza()->getYwyborStatku()<=9 && rozgrywka.stanGry!=0 && rozgrywka.stanGry!=4)
        {
            if(rozgrywka.stanGry==1/*STAN_DODAWANIE_POCZ_STATKU*/)
            {
                if(!kolizja)
                {
                   ui->label->setText("             PODAJ PUNKT POCZATKOWY STATKU!");
                }
                rozgrywka.x_pocz_tmp=rozgrywka.udostepnijGracza()->getXwyborStatku();
                rozgrywka.y_pocz_tmp=rozgrywka.udostepnijGracza()->getYwyborStatku();
                //cout << "wybrano pkt poczatkowy: "<<x<<" , "<<y<<endl;
                scene_p->addRect(rozgrywka.udostepnijGracza()->getXwyborStatku()*SQUARE,rozgrywka.udostepnijGracza()->getYwyborStatku()*SQUARE,30,30,blackPen,redBrush);
                rozgrywka.stanGry=STAN_DODAWANIE_KON_STATKU;
                ui->zapisz->setEnabled(false);
                ui->wczytaj->setEnabled(false);
                ui->label->setText("                PODAJ PUNKT KONCOWY STATKU!");

            }
            else if(rozgrywka.stanGry==2/*STAN_DODAWANIE_KON_STATKU*/)
            {
                ui->zapisz->setEnabled(true);
                ui->wczytaj->setEnabled(true);
                cout << "wybrano pkt koncowy: "<<rozgrywka.udostepnijGracza()->getXwyborStatku()<<" , "<<rozgrywka.udostepnijGracza()->getYwyborStatku()<<endl;

                if(rozgrywka.x_pocz_tmp==rozgrywka.udostepnijGracza()->getXwyborStatku() || rozgrywka.y_pocz_tmp==rozgrywka.udostepnijGracza()->getYwyborStatku())
                {
                    if(rozgrywka.udostepnijGracza()->getXwyborStatku()<rozgrywka.x_pocz_tmp)
                    {
                        int tmp;
                        tmp=rozgrywka.udostepnijGracza()->getXwyborStatku();
                        rozgrywka.udostepnijGracza()->setXwyborStatku(rozgrywka.x_pocz_tmp);
                        rozgrywka.x_pocz_tmp=tmp;
                    }
                    if(rozgrywka.udostepnijGracza()->getYwyborStatku()<rozgrywka.y_pocz_tmp)
                    {
                        int tmp;
                        tmp=rozgrywka.udostepnijGracza()->getYwyborStatku();
                        rozgrywka.udostepnijGracza()->setYwyborStatku(rozgrywka.y_pocz_tmp);
                        rozgrywka.y_pocz_tmp=tmp;
                    }
                    if(rozgrywka.udostepnijMapeGracza()->dodajStatek(rozgrywka.x_pocz_tmp,rozgrywka.y_pocz_tmp,rozgrywka.udostepnijGracza()->getXwyborStatku(),rozgrywka.udostepnijGracza()->getYwyborStatku()))
                    {
                        rozgrywka.stanGry=1;/*STAN_DOD_POCZ*/
                        if(rozgrywka.udostepnijMapeGracza()->getStatkiPlywajace() != NULL)
                        {
                            ui->rozpocznij_gre->setEnabled(true);
                        }
                        kolizja=false;
                        cout<<"DODANO STATEK : "<<rozgrywka.x_pocz_tmp<<", "<<rozgrywka.y_pocz_tmp<<", "<<rozgrywka.udostepnijGracza()->getXwyborStatku()<<", "<<rozgrywka.udostepnijGracza()->getYwyborStatku()<<endl;
                    }
                    else
                    {
                        ui->label->setText("        KOLIZJA Z INNYM STATKIEM, WYBIERZ PONOWNIE");
                        cout << "kolizja";
                        kolizja = true;
                        rozgrywka.stanGry=1;/*STAN_DOD_POCZ_STATKU*/
                    }
                }
                else
                {
                    ui->label->setText("        NIEPOPRAWNE WSPOLRZEDNE STATKU, WYBIERZ PONOWNIE");
                    rozgrywka.stanGry=1;/*STAN_DOD_POCZ_STATKU*/
                }
                GUI.aktualizujGUI(rozgrywka,scene_p,scene_cpu);
                if(!kolizja)
                {
                   ui->label->setText("               PODAJ PUNKT POCZATKOWY STATKU!");
                }
            }
        }
        if(rozgrywka.stanGry==3 && rozgrywka.udostepnijGracza()->getXstrzal()>=0 && rozgrywka.udostepnijGracza()->getXstrzal()<=9 && rozgrywka.udostepnijGracza()->getYstrzal()>=0 && rozgrywka.udostepnijGracza()->getYstrzal()<=9)
        {
            {
                ui->zapisz->setEnabled(true);
                ui->wczytaj->setEnabled(true);
                ui->konfiguruj_gre->setEnabled(false);
                ui->rozpocznij_gre->setEnabled(false);
                ui->resetuj->setEnabled(true);
                ui->zakoncz->setEnabled(true);
                ui->label->setText("                      ODDAJ STRZAL!");
                GUI.aktualizujGUI(rozgrywka,scene_p,scene_cpu);

                Mapa *mapa_cpu = rozgrywka.udostepnijMapeCPU();
                Mapa *mapa_gracza = rozgrywka.udostepnijMapeGracza();
                Cpu *CPU = rozgrywka.udostepnijCPU();
                Gracz *Gracz = rozgrywka.udostepnijGracza();
                bool czyStrzalPoprawny;

                if(rozgrywka.getKolejGracza())
                {
                    czyStrzalPoprawny= Gracz->oddajStrzal(Gracz->getXstrzal(),Gracz->getYstrzal(),mapa_cpu);
                    GUI.aktualizujGUI(rozgrywka,scene_p,scene_cpu);
                    if(czyStrzalPoprawny)
                    {
                        if(CPU->sprawdzCzyTrafionyZatopiony(Gracz->getXstrzal(),Gracz->getYstrzal(),mapa_cpu))
                        {
                            ui->label->setText("                   TRAFIONY ZATOPIONY!!");
                        }
                        rozgrywka.setKolejGracza(false);
                        if(CPU->sprawdzCzyFlotaGraczaZatopiona(mapa_cpu))
                        {
                            rozgrywka.setGraczWygral(true);
                        }
                        if(rozgrywka.getGraczWygral())
                        {
                            ui->label->setText("                 KONIEC GRY!!! WYGRALES!!!");
                            rozgrywka.stanGry=4;/*STAN__KONIEC*/
                        }
                        if(!rozgrywka.getGraczWygral())
                        {
                            CPU->getAktualnyAlgorytm()->wykonajAlgorytm(mapa_gracza,Gracz,CPU);
                            GUI.aktualizujGUI(rozgrywka,scene_p,scene_cpu);
                            if(Gracz->sprawdzCzyFlotaGraczaZatopiona(mapa_gracza))
                            {
                                rozgrywka.setCpuWygral(true);
                            }
                            if(rozgrywka.getCpuWygral())
                            {
                                ui->label->setText("                KONIEC GRY!!! PRZEGRALES!!!");
                                rozgrywka.stanGry=4;/*STAN_KONIEC*/
                            }
                        }
                        if(!rozgrywka.getGraczWygral() && !rozgrywka.getCpuWygral())
                        {
                            rozgrywka.setKolejGracza(true);
                        }
                    }
                    else
                    {
                        ui->label->setText("               SPROBUJ STRZELIC JESZCZE RAZ!!!");
                    }
                }
                else
                {
                    CPU->getAktualnyAlgorytm()->wykonajAlgorytm(mapa_gracza,Gracz,CPU);
                    GUI.aktualizujGUI(rozgrywka,scene_p,scene_cpu);
                    if(Gracz->sprawdzCzyFlotaGraczaZatopiona(mapa_gracza))
                    {
                        rozgrywka.setCpuWygral(true);
                    }
                    if(rozgrywka.getCpuWygral())
                    {
                        ui->label->setText("                KONIEC GRY!!! PRZEGRALES!!!");
                        rozgrywka.stanGry=4;/*STAN_KONIEC*/
                    }
                    else
                    {
                        rozgrywka.setKolejGracza(true);
                        czyStrzalPoprawny= Gracz->oddajStrzal(Gracz->getXstrzal(),Gracz->getYstrzal(),mapa_cpu);
                        GUI.aktualizujGUI(rozgrywka,scene_p,scene_cpu);
                        if(czyStrzalPoprawny)
                        {
                            if(CPU->sprawdzCzyTrafionyZatopiony(Gracz->getXstrzal(),Gracz->getYstrzal(),mapa_cpu))
                            {
                                ui->label->setText("                   TRAFIONY ZATOPIONY!!");
                            }
                            rozgrywka.setKolejGracza(false);
                            if(CPU->sprawdzCzyFlotaGraczaZatopiona(mapa_cpu))
                            {
                                rozgrywka.setGraczWygral(true);
                            }
                            if(rozgrywka.getGraczWygral())
                            {
                                ui->label->setText("                 KONIEC GRY!!! WYGRALES!!!");
                                rozgrywka.stanGry=4;/*STAN__KONIEC*/
                            }
                        }
                        else
                        {
                            rozgrywka.setKolejGracza(true);
                        }
                    }
                }
            }
            update();
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_konfiguruj_gre_clicked()
{
    ui->konfiguruj_gre->setEnabled(false);
    rozgrywka.resetRozgrywki();
    GUI.aktualizujGUI(rozgrywka,scene_p,scene_cpu);
    rozgrywka.stanGry=STAN_DODAWANIE_POCZ_STATKU;
    ui->label->setText("            DODAJ WSPOLRZEDNE POCZATKU STATKU");
}

void MainWindow::on_rozpocznij_gre_clicked()
{
    Mapa *mapa_cpu = rozgrywka.udostepnijMapeCPU();
    Mapa *mapa_gracza = rozgrywka.udostepnijMapeGracza();
    Cpu *CPU = rozgrywka.udostepnijCPU();
    if(!CPU->rozmiescStatki(mapa_cpu,mapa_gracza->getParametryDlaCpu()))
    {
        ui->label->setText("    BLAD LADOWANIA STATKOW PRZECIWNIKA, ZRESTARTUJ GRE");
    }
    ui->rozpocznij_gre->setEnabled(false);
    rozgrywka.stanGry=3;
    ui->label->setText("                      ODDAJ STRZAL!");
    ui->algorytm->setEnabled(false);
    this->zmianaAlgorytmu(ui->algorytm->currentText());
}

void MainWindow::on_resetuj_clicked()
{
    ui->konfiguruj_gre->setEnabled(true);
    ui->rozpocznij_gre->setEnabled(false);
    ui->zapisz->setEnabled(false);
    ui->wczytaj->setEnabled(true);
    rozgrywka.resetRozgrywki();
    GUI.aktualizujGUI(rozgrywka,scene_p,scene_cpu);
    rozgrywka.stanGry=STAN_START;
    ui->label->setText("   ABY ROZPOCZAC GRE, WCISNIJ PRZYCISK KONFIGURUJ GRE");
    ui->algorytm->setEnabled(true);
}

void MainWindow::on_zakoncz_clicked()
{
    rozgrywka.resetRozgrywki();
    QCoreApplication::quit();
}

void MainWindow::zmianaAlgorytmu(QString napis)
{
    Cpu *CPU = rozgrywka.udostepnijCPU();
    if(napis=="Algorytm Inteligentny")
    {
        CPU->setAktualnyAlgorytm(ALGINT);
    }
    else if (napis=="Algorytm Losowy")
    {
        CPU->setAktualnyAlgorytm(ALGLOS);
    }
    else if (napis=="Algorytm Jak Gracz")
    {
        CPU->setAktualnyAlgorytm(ALGJAKGRACZ);
    }
}
