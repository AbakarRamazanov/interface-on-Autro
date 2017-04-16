#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QVector>
#include <QLabel>
#include <QString>
#include <QTextEdit>
#include <QDebug>

class interface : public QWidget
{
    Q_OBJECT
public:
    explicit interface(QWidget *parent = 0);
    QGridLayout *qgl;
    QLineEdit *qleStatus;
    QLineEdit *qleEntrance;
    QPushButton *qpbCountSE;
    QPushButton *qpbInputSE;
    QLabel *qlabelStatus;
    QLabel *qlabelEntrance;
    QVector<QLineEdit*> qvQleStatus;
    QVector<QLineEdit*> qvQleEntrance;
    QVector<QLineEdit*> qvQleTransform;
    QVector<QLineEdit*> qvQleExit;
    QLineEdit *qleInput;
    QPushButton *qpbInput;
    QLabel *qlabelStatusResult;
    QLabel *qlabelExitResult;
    QWidget *qwdjCode;
    QTextEdit *qteCode;
signals:
    void signalProcces(QStringList str);
    void signalAutro( QVector<QLineEdit*> qvQleStatus,
                      QVector<QLineEdit*> qvQleEntrance,
                      QVector<QLineEdit*> qvQleTransform,
                      QVector<QLineEdit*> qvQleExit  );
public slots:
    void CreateQvSE();
    void CreateResult();
    void slotSignalProcces();
    void resultProccess(QStringList Status, QStringList Exit, QString Code);
};

#endif // INTERFACE_H
