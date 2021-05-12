#include "gui.h"

GUI::GUI()
{

}

void GUI::aktualizujGUI(Rozgrywka rozgrywka, QGraphicsScene *scene_p, QGraphicsScene *scene_cpu)
{
    QBrush blueBrush(Qt::blue);
    QBrush greenBrush(Qt::green);
    QBrush grayBrush (Qt::lightGray);
    QBrush redBrush (Qt::red);
    QPen blackPen (Qt::black);
    Mapa *akt = rozgrywka.udostepnijMapeGracza();
    Mapa *akt2 = rozgrywka.udostepnijMapeCPU();
    char *polaGracza = akt->getPola();
    char *polaCPU = akt2->getPola();
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(*((polaGracza+i*len)+j)=='s')
            {
                scene_p->addRect(j*SQUARE,i*SQUARE,30,30,blackPen,greenBrush);
            }
            else if (*((polaGracza+i*len)+j)=='w')
            {
                scene_p->addRect(j*SQUARE,i*SQUARE,30,30,blackPen,grayBrush);
            }
            else if (*((polaGracza+i*len)+j)=='x')
            {
                scene_p->addRect(j*SQUARE,i*SQUARE,30,30,blackPen,redBrush);
            }
            else if(*((polaGracza+i*len)+j)=='n')
            {
                scene_p->addRect(j*SQUARE,i*SQUARE,30,30,blackPen,blueBrush);
            }
            if(*((polaCPU+i*len)+j)=='x')
            {
                scene_cpu->addRect(j*SQUARE,i*SQUARE,30,30,blackPen,redBrush);
            }
            else if(*((polaCPU+i*len)+j)=='n')
            {
                scene_cpu->addRect(j*SQUARE,i*SQUARE,30,30,blackPen,blueBrush);
            }
            else if(*((polaCPU+i*len)+j)=='w')
            {
                scene_cpu->addRect(j*SQUARE,i*SQUARE,30,30,blackPen,grayBrush);
            }
            else if(*((polaCPU+i*len)+j)=='s')
            {
                scene_cpu->addRect(j*SQUARE,i*SQUARE,30,30,blackPen,grayBrush);
            }
        }
    }
    scene_p->update();
    scene_cpu->update();
}

void GUI::skonfigurujGUI(QGraphicsScene *scene_p, QGraphicsScene *scene_cpu)
{
    QBrush grayBrush(Qt::lightGray);
    QPen blackPen (Qt::black);

    blackPen.setWidth(1);

    int offset = SQUARE;

    //rysowanie planszy

    for (int n=0,x = -30; n <= WID;++n,x += offset)  //-30
    {
        for (int m=0,y = -30; m <= LEN;++m,y += offset)  //-30
        {
            scene_p->addRect(x, y, offset, offset, blackPen, grayBrush);          //'n' - nic nie ma na polu (brak strzału, brak statku)
            scene_cpu->addRect(x, y, offset, offset, blackPen, grayBrush);
        }
    }
}
