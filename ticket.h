#ifndef TICKET_H
#define TICKET_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include<qsqlquerymodel.h>

class Ticket
{
private:
    int id,horaire_entr,horaire_arr,num_mat;
    float prix;
public:
    //Constructeurs
    Ticket();
     Ticket(int,int,int,int,float);
     //Getters
     int getid();
     int gethoraire_entr();
     int gethoraire_arr();
     int getnum_mat();
     float getprix();
     //Setters
     void setid(int);
     void sethoraire_entr(int);
     void sethoraire_arr(int);
     void setnum_mat(int);
     void setprix(float);
     //Fonctionnalités de Base relatives à l'entité Ticket
     bool ajouter();
     QSqlQueryModel * afficher();
     bool supprimer(int);
     bool modifier();
};

#endif // TICKET_H
