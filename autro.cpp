#include "autro.h"

autro::autro(QObject *parent) : QObject(parent)
{
}

void autro::Processing(QStringList Input)
{
    QString sActual = S[0];
    QStringList Status;
    QStringList Exit;
    foreach (QString Str, Input) {
        Status.push_back(sActual);
        Exit.push_back(Y[sActual][Str]) ;
        sActual = ST[sActual][Str];
    }
    emit resultProcessing(Status, Exit, Code);
}

void autro::Code_Generation()
{
    QString Current_Str;
    Current_Str = "switch(Input)\n{\n";
    foreach (QString Inputs, X) {
        Current_Str.append("\tcase ");
        Current_Str.append(Inputs);
        Current_Str.append(" :\n\t\t{\n");
        Current_Str.append("\t\t\tswitch (Status)\n\t\t\t\t{\n");
        foreach (QString State, S) {
            Current_Str.append("\t\t\t\t\tcase ");
            Current_Str.append(State);
            Current_Str.append(" :\n\t\t\t\t{\n");
            Current_Str += "\t\t\t\t\t\t\tstd::cout << Entrance.find(" + Inputs + "," + State + ") << std::endl;\n";
            Current_Str += "\t\t\t\t\t\t\tStatus = Transform.find(" + Inputs + "," + State + ");\n";
            Current_Str.append("\t\t\t\t\t\t\tbreak;\n\n\t\t\t\t}\n");
        }
        Current_Str.append("\t\t\tbreak;\n\t\t}\n");
    }
    Current_Str.append("}");
    Code.append(Current_Str);
}


void autro::Input_S(    QVector<QLineEdit*> qvQleStatus,
                        QVector<QLineEdit*> qvQleEntrance,
                        QVector<QLineEdit*> qvQleTransform,
                        QVector<QLineEdit*> qvQleExit  )
{
    foreach (QLineEdit* str, qvQleStatus) {
        S.push_back(str->text());
    }
    foreach (QLineEdit* str, qvQleEntrance) {
        X.push_back(str->text());
    }
    int i, j, k = 0;
    for(i = 0; i < S.size(); i++)
    {
        for(j = 0; j < X.size(); j++)
        {
            ST[S[i]][X[j]]=qvQleTransform[k]->text();
            Y[S[i]][X[j]]=qvQleExit[k]->text();
            k++;
        }
    }
    Code_Generation();
    /*
    qDebug() << "S: \t";
    foreach (QString str, S)
    {
        qDebug() << str << "\t";
    }
    qDebug() << "\nX: \t";
    foreach (QString str, X)
    {
        qDebug() << str << "\t";
    }
    qDebug() << "\nY: \t";
    for(i = 0; i < S.size(); i++)
    {
        for(j = 0; j < X.size(); j++)
        {
            qDebug() << Y[S[i]][X[j]] << "\t";
        }
    }
    qDebug() << "\nST: \t";
    for(i = 0; i < S.size(); i++)
    {
        for(j = 0; j < X.size(); j++)
        {
            qDebug() << ST[S[i]][X[j]] << "\t";
        }
    }*/
}

QString autro::get_Code()
{
    return Code;
}



























