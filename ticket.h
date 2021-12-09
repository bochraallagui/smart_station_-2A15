#ifndef TICKET_H
#define TICKET_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <qsqlquerymodel.h>
#include <vector>

class Ticket
{
private:
    int idt,horaire_entr,horaire_arr;
    float prix;
public:
    //Constructeurs
     Ticket();
     Ticket(int,int,int,float);
     //Getters
     int getid();
     int gethoraire_entr();
     int gethoraire_arr();
     float getprix();
     //Setters
     void setid(int);
     void sethoraire_entr(int);
     void sethoraire_arr(int);
     void setprix(float);
     //Fonctionnalités de Base relatives à l'entité Ticket
     bool ajouter();
     QSqlQueryModel * afficher();
     bool supprimer(int);
     bool modifier();

     QSqlQueryModel *recherche_ID(int idt);
     QSqlQueryModel *recherche_prix(int prix);
     QSqlQueryModel *recherche_horaire_entr(int horaire_entr);
     QSqlQueryModel *triparid();
     QSqlQueryModel *triparhoraire_entr();
     QSqlQueryModel *triparprix();
     void statistique(QVector<double>* ticks,QVector<QString> *labels);
     QSqlQueryModel *ticketVIP();
};

#endif // TICKET_H
