#ifndef AUTRO_H
#define AUTRO_H
#include <QTextStream>
#include <QString>
#include <QMap>
#include <QVector>
#include <QDebug>
#include <QLineEdit>

class autro : public QObject
{
    Q_OBJECT
    QVector<QString> X;
    QVector<QString> S;
    QMap<QString, QMap<QString, QString> > Y;
    QMap<QString, QMap<QString, QString> > ST;
    QString Code;
public:
    void Code_Generation();
    explicit autro(QObject *parent = 0);
    QString get_Code();
signals:
    void resultProcessing(QStringList Status, QStringList Exit, QString Code);
public slots:
    void Input_S(    QVector<QLineEdit*> qvQleStatus,
                     QVector<QLineEdit*> qvQleEntrance,
                     QVector<QLineEdit*> qvQleTransform,
                     QVector<QLineEdit*> qvQleExit  );
    void Processing(QStringList Input);
};

#endif // AUTRO_H
