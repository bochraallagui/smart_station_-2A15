#include "ticket.h"
#include"mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <vector>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <qcustomplot.h>

Ticket::Ticket()
{
    idt=0;
    horaire_entr=0;
    horaire_arr=0;
    prix=0;
}

Ticket::Ticket(int idt,int entr,int arr,float p)
{
    this->idt=idt;
    this->horaire_entr=entr;
    this->horaire_arr=arr;
    this->prix=p;
}
int Ticket::getid(){return idt;}
int Ticket::gethoraire_entr(){return horaire_entr;}
int Ticket::gethoraire_arr(){return horaire_arr;}
float Ticket::getprix(){return prix;}
void Ticket::setid(int idt){this->idt=idt;}
void Ticket::sethoraire_entr(int entr){this->horaire_entr=entr;}
void Ticket::sethoraire_arr(int arr){this->horaire_arr=arr;}
void Ticket::setprix(float p){this->prix=p;}

bool Ticket::ajouter()
{
    QSqlQuery query;
    QString idt_string=QString::number(idt);
    QString horaire_entr_string=QString::number(horaire_entr);
    QString horaire_arr_string=QString::number(horaire_arr);
    QString prix_string=QString::number(prix);

    query.prepare("insert into tickets(idt,horaire_entr,horaire_arr,prix) values (:idt,:horaire_entr,:horaire_arr,:prix)");

    //Création des variables liées
    query.bindValue(0,  idt_string);
    query.bindValue(1,  horaire_entr_string);
    query.bindValue(2,  horaire_arr_string);
    query.bindValue(3,  prix_string);

     return query.exec(); //exec() envoie la requete pour l'executer
}

QSqlQueryModel * Ticket::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();//remplir tab //QSqlQueryModel : reading from SQL

              model->setQuery("SELECT* FROM tickets");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("idt")); // ajouter nom colon
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("horaire_entr"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("horaire_arr"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));


        return model;
}

bool Ticket::supprimer(int idt)
{
    QSqlQuery query;
              query.prepare("Delete from tickets where idt=:idt");

              query.bindValue(0, idt);

              query.exec();
}

bool Ticket::modifier()
{

    QSqlQuery query;
    QString idt_string=QString::number(idt);
    QString horaire_entr_string=QString::number(horaire_entr);
    QString horaire_arr_string=QString::number(horaire_arr);
    QString prix_string=QString::number(prix);
        query.prepare("UPDATE tickets SET idt=:idt,horaire_entr=:horaire_entr,horaire_arr=:horaire_arr,prix=:prix WHERE idt=:idt ");
        query.bindValue(":idt",idt_string); //liasion valeur/parametre
        query.bindValue(":horaire_entr", horaire_entr_string);
        query.bindValue(":horaire_arr", horaire_arr_string);
        query.bindValue(":prix", prix_string);
        query.exec();
}



QSqlQueryModel* Ticket::triparid()
{
    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM tickets order by idt ASC");
    q->exec();
                     model->setQuery(*q);
                     model->setHeaderData(0, Qt::Horizontal, QObject::tr("idt"));
                     model->setHeaderData(1, Qt::Horizontal, QObject::tr("horaire_entr"));
                     model->setHeaderData(2, Qt::Horizontal, QObject::tr("horaire_arr"));
                     model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
                     return model;
}

QSqlQueryModel* Ticket::triparhoraire_entr()
{
    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM tickets order by horaire_entr ASC");
    q->exec();
                     model->setQuery(*q);
                     model->setHeaderData(0, Qt::Horizontal, QObject::tr("idt"));
                     model->setHeaderData(1, Qt::Horizontal, QObject::tr("horaire_entr"));
                     model->setHeaderData(2, Qt::Horizontal, QObject::tr("horaire_arr"));
                     model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
                     return model;
}

QSqlQueryModel* Ticket::triparprix()
{
    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM tickets order by prix ASC");
    q->exec();
                     model->setQuery(*q);
                     model->setHeaderData(0, Qt::Horizontal, QObject::tr("idt"));
                     model->setHeaderData(1, Qt::Horizontal, QObject::tr("horaire_entr"));
                     model->setHeaderData(2, Qt::Horizontal, QObject::tr("horaire_arr"));
                     model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
                     return model;
}
QSqlQueryModel* Ticket::recherche_ID(int idt)
{
    QSqlQueryModel *model=new QSqlQueryModel();
                QString res=QString ::number(idt);
            model->setQuery("select * from tickets where IDT='"+res+"'");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("idt")); // ajouter nom colon
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("horaire_entr"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("horaire_arr"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

   return model;

}

QSqlQueryModel* Ticket::recherche_prix(int prix)
{
    QSqlQueryModel *model=new QSqlQueryModel();
                QString res=QString ::number(prix);
            model->setQuery("select * from tickets where prix='"+res+"'");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("idt")); // ajouter nom colon
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("horaire_entr"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("horaire_arr"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

   return model;
}

QSqlQueryModel* Ticket::recherche_horaire_entr(int horaire_entr)
{
    QSqlQueryModel *model=new QSqlQueryModel();
                QString res=QString ::number(horaire_entr);
            model->setQuery("select * from tickets where horaire_entr='"+res+"'");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("idt")); // ajouter nom colon
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("horaire_entr"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("horaire_arr"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

   return model;
}

void Ticket::statistique(QVector<double>* ticks,QVector<QString> *labels)
{
    QSqlQuery q;
    int i=0;
    q.exec("select horaire_entr from Tickets");
    while (q.next())
    {
        QString identifiant = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<identifiant;
    }
}

QSqlQueryModel * Ticket::ticketVIP()
{
    QSqlQueryModel * model = afficher();
    int max=model->data(model->index(0,3)).toInt();

    for (int i=0;i<model->rowCount();i++){
        if (model->data(model->index(i,3)).toInt()>max)
            max=model->data(model->index(i,3)).toInt();

    }

    QString res=QString::number(max);
    model->setQuery("select * from tickets where prix='"+res+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id")); // ajouter nom colon
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("horaire_entr"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("horaire_arr"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
    return model;
}
