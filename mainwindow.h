#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifndef GUI_H
#include "gui.h"
#endif

#ifndef SERIALIZACJA_H
#include "serializacja.h"
#endif

#include <QMainWindow>
#include <QPointF>
#include <QMouseEvent>
#include "rozgrywka.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Rozgrywka rozgrywka;
    Serializacja serializacja;
    GUI GUI;
    QGraphicsScene *scene_p; //scena gracza
    QGraphicsScene *scene_cpu; // scena cpu
    void wczytajPunktKlikniecia (int Xmyszki, int Ymyszki);
    void zmianaAlgorytmu (QString napis);

private slots:
    void mousePressEvent(QMouseEvent *event);
    void on_konfiguruj_gre_clicked();
    void on_rozpocznij_gre_clicked();
    void on_resetuj_clicked();
    void on_zakoncz_clicked();
};
#endif // MAINWINDOW_H
