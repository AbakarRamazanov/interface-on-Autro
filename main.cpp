#include <QApplication>
#include "interface.h"
#include "autro.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    interface *inter = new interface;
    autro *autr = new autro;
    QObject::connect(inter,interface::signalAutro, autr, autro::Input_S);
    QObject::connect(inter,interface::signalProcces, autr, autro::Processing);
    QObject::connect(autr, autro::resultProcessing, inter, interface::resultProccess);
    return a.exec();
}
