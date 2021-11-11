#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ticket.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QTabWidget>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_ID->setValidator(new QIntValidator(0 , 9999999, this));
    ui->tab_ticket->setModel(T.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_ID->text().toInt();
    int entr=ui->le_Horaire_entr->text().toInt();
    int arr=ui->le_Horaire_arr->text().toInt();
    int mat=ui->le_Num_mat->text().toInt();
    float p=ui->le_Prix->text().toFloat();

        Ticket T(id,entr,arr,mat,p);
        bool test=T.ajouter();
        QMessageBox msgBox;
            if(test)
                msgBox.setText("ajout avec succes");
                else
                msgBox.setText(("echec d'ajout"));

                msgBox.exec();
}

void MainWindow::on_pb_supp_clicked()
{
    Ticket T1;
    T1.setid(ui->le_ID_supp->text().toInt());
    bool test=T1.supprimer(T1.getid());
    QMessageBox msgBox;
        if(test)
            msgBox.setText("suppresion avec succes");
            else
            msgBox.setText(("echec de suppresion"));

            msgBox.exec();

}
void MainWindow::on_pb_modifier_clicked()
{

    int id=ui->le_ID_2->text().toInt();
    int entr=ui->le_Horaire_entr_2->text().toInt();
    int arr=ui->le_Horaire_arr_2->text().toInt();
    int mat=ui->le_Num_mat_2->text().toInt();
    float p=ui->le_Prix_2->text().toFloat();

    Ticket T(id,entr,arr,mat,p);
    bool test=T.modifier();

        QMessageBox msgBox;
            if(test)
                msgBox.setText("modification avec succes");
                else
                msgBox.setText(("echec de modification"));

                msgBox.exec();

}
