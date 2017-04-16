#include "interface.h"

interface::interface(QWidget *parent) : QWidget(parent)
{
    qgl = new QGridLayout(this);
    qgl->setSpacing(10);
    qleStatus = new QLineEdit(this);
    qleEntrance = new QLineEdit(this);
    qpbCountSE = new QPushButton("Push", this);
    QWidget::connect(qpbCountSE, QPushButton::clicked, this, interface::CreateQvSE);
    qgl->addWidget(qleStatus, 0 , 0, 1, 1);
    qgl->addWidget(qleEntrance, 0, 1, 1, 1);
    qgl->addWidget(qpbCountSE, 0, 2, 1, 1);
    show();
}

void interface::CreateQvSE()
{
    qpbCountSE->setEnabled(false);
    hide();
//    qlabelStatus = new QLabel("Status", this);
//    qgl->addWidget(qlabelStatus, 1, 0, 1, 1);
    int i, n = qleStatus->text().toInt();
    QLineEdit *p;
    for(i = 0; i < n ; i++ )
    {
        p = new QLineEdit(this);
        p->setStyleSheet("background:#bf2;");
        qvQleStatus.push_back(p);
        qgl->addWidget(qvQleStatus.back(), 1, i + 1, 1, 1);
    }
//    qlabelEntrance = new QLabel("Entrance", this);
//    qgl->addWidget(qlabelEntrance, 2, 0, 1, 1);
    int j, m = qleEntrance->text().toInt();
    for(j = 0; j < m ; j++ )
    {
        p = new QLineEdit(this);
        p->setStyleSheet("background:#f31;");
        qvQleEntrance.push_back(p);
        qgl->addWidget(qvQleEntrance.back(), 2 * (j + 1), 0, 2, 1);
    }


    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            p = new QLineEdit(this);
            qvQleTransform.push_back(p);
            qgl->addWidget(qvQleTransform.back(), (j + 1) * 2, i + 1, 1, 1 );
            p = new QLineEdit(this);
            qvQleExit.push_back(p);
            qgl->addWidget(qvQleExit.back(), (j + 1) * 2 + 1, i + 1, 1, 1 );
        }
    }
    qpbInputSE = new QPushButton("Push", this);
    qgl->addWidget(qpbInputSE, (m + 1) * 2, 0, 1, n + 1);
    QWidget::connect(qpbInputSE, QPushButton::clicked, this, interface::CreateResult);
    show();
}

void interface::CreateResult()
{
    hide();
    emit signalAutro( qvQleStatus,
                      qvQleEntrance,
                      qvQleTransform,
                      qvQleExit  );
    qpbInputSE->setEnabled(false);
    qleInput = new QLineEdit(this);
    qpbInput = new QPushButton("Push",this);
    qgl->addWidget(qleInput, ( qleEntrance->text().toInt() + 1 ) * 2 + 1, 0, 1, qleStatus->text().toInt());
    qgl->addWidget(qpbInput, ( qleEntrance->text().toInt() + 1 ) * 2 + 1, qleStatus->text().toInt(), 1, 1);
    QWidget::connect(qpbInput, QPushButton::clicked, this, interface::slotSignalProcces);
    show();
}

void interface::slotSignalProcces()
{
    emit signalProcces(qleInput->text().split(","));
}

void interface::resultProccess(QStringList Status, QStringList Exit, QString Code)
{
    hide();
    qlabelStatusResult = new QLabel;
    qlabelExitResult = new QLabel;
    qlabelStatusResult->setText(Status.join("\n"));
    qlabelExitResult->setText(Exit.join("\n"));
    qgl->addWidget(qlabelStatusResult, 0, qleStatus->text().toInt() + 1);
    qgl->addWidget(qlabelExitResult, 0, qleStatus->text().toInt() + 2);
    show();
    qwdjCode = new QWidget(this,Qt::Window | Qt::WindowMaximizeButtonHint);
    qteCode = new QTextEdit(qwdjCode);
    qteCode->setText(Code);
    qteCode->setReadOnly(true);
    qteCode->resize(1100,550);
    qwdjCode->resize(1120,570);
    qwdjCode->move(5,5);
    qwdjCode->show();
}
