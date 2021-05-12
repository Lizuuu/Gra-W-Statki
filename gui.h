#ifndef GUI_H
#define GUI_H

#ifndef MAPA_H
#include "mapa.h"
#endif

#ifndef ROZGRYWKA_H
#include "rozgrywka.h"
#endif

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>

class GUI
{
public:
    GUI();

    void aktualizujGUI(Rozgrywka rozgrywka, QGraphicsScene *scene_p, QGraphicsScene *scene_cpu);
    void skonfigurujGUI(QGraphicsScene *scene_p, QGraphicsScene *scene_cpu);
};

#endif // GUI_H
