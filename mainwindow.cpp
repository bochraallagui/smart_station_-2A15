#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ticket.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QRegExpValidator>
#include "qcustomplot.h"
#include <QTableView>
#include <QAbstractItemView>
#include <QLineEdit>
#include <QSqlQuery>
#include<qcustomplot.h>
#include <QPlainTextEdit>
#include <QPrinter>
#include <QPrinterInfo>
#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include "qcustomplot.h"
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QtSvg/QSvgRenderer>
#include "QRcode.hhp"
#include <iostream>
#include <fstream>

 using qrcodegen::QrCode;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); //pointe sur l'intrfc ,recuperer la valeur saisie
    ui->le_ID->setValidator(new QIntValidator(0 , 9999999, this));//control saisie
    ui->le_Horaire_entr->setValidator(new QIntValidator(0 , 23, this));
    ui->le_Horaire_arr->setValidator(new QIntValidator(0 , 23, this));
    ui->le_Prix->setValidator(new QIntValidator(0 , 9999999, this));
    ui->tab_ticket_2->setModel(T.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_4_clicked()
{
    int idt=ui->le_ID->text().toInt();
    int entr=ui->le_Horaire_entr->text().toInt();
    int arr=ui->le_Horaire_arr->text().toInt();
    float p=ui->le_Prix->text().toFloat();

        Ticket T(idt,entr,arr,p);
        bool test=T.ajouter();
        QMessageBox msgBox;
            if(test)
            {ui->tab_ticket_2->setModel(T.afficher());
                msgBox.setText("ajout avec succes");}
                else
                msgBox.setText(("echec d'ajout"));

                msgBox.exec();
}

void MainWindow::on_pb_supp_2_clicked()
{
    Ticket T1;
    T1.setid(ui->le_ID_2->text().toInt());
    bool test=T1.supprimer(T1.getid());
    QMessageBox msgBox;
        if(test)
        { ui->tab_ticket_2->setModel(T.afficher());
            msgBox.setText("suppresion avec succes");}
            else
            msgBox.setText(("echec de suppresion"));

            msgBox.exec();

}

void MainWindow::on_pb_modifier_5_clicked()
{
    int idt=ui->le_ID_2->text().toInt();
    int entr=ui->le_Horaire_entr_2->text().toInt();
    int arr=ui->le_Horaire_arr_2->text().toInt();
    float p=ui->le_Prix_2->text().toFloat();

    Ticket T(idt,entr,arr,p);
    bool test=T.modifier();

        QMessageBox msgBox;
            if(test)
            {ui->tab_ticket_2->setModel(T.afficher());
                msgBox.setText("modification avec succes");}
                else
                msgBox.setText(("echec de modification"));

                msgBox.exec();

}




 void MainWindow::on_pb_recherche_ID_2_clicked()
{
    int idt=ui->lineEdit->text().toInt();
    if (idt==NULL) {
        QMessageBox::information(this, tr("Empty Field"),
            tr("Please enter a Number."));
        return;
    } else {
    ui->tab_ticket_2->setModel(T.recherche_ID(idt));
    }
}

void MainWindow::on_pb_recherche_PRIX_2_clicked()
{
    int prix=ui->lineEdit_2->text().toInt();
    if (prix==NULL) {
        QMessageBox::information(this, tr("Empty Field"),
            tr("Please enter a Number."));
        return;
    } else {
    ui->tab_ticket_2->setModel(T.recherche_prix(prix));
    }
}

void MainWindow::on_pb_recherche_horaire_entr_2_clicked()
{
    int horaire_entr=ui->lineEdit_3->text().toInt();
    if (horaire_entr==NULL) {
        QMessageBox::information(this, tr("Empty Field"),
            tr("Please enter a Number."));
        return;
    } else {
    ui->tab_ticket_2->setModel(T.recherche_horaire_entr(horaire_entr));
    }
}

void MainWindow::on_tabWidget_currentChanged(int index) //statistique
{
                    // background //
                     QLinearGradient gradient(0, 0, 0, 400);
                     gradient.setColorAt(0, QColor(900, 900, 900));
                     gradient.setColorAt(0.38, QColor(105, 105, 105));
                     gradient.setColorAt(1, QColor(100, 100, 100));
                     ui->plot->setBackground(QBrush(gradient));

                     QCPBars *amande = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
                     amande->setAntialiased(false);
                     amande->setStackingGap(1);
                      //couleurs
                     amande->setName("horaire d'entrées des tickets");
                     amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
                     amande->setBrush(QColor(0, 168, 200));

                      //axe des abscisses
                     QVector<double> ticks;
                     QVector<QString> labels;
                     T.statistique(&ticks,&labels);
                     QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
                     textTicker->addTicks(ticks, labels);
                     ui->plot->xAxis->setTicker(textTicker);
                     ui->plot->xAxis->setTickLabelRotation(0);
                     ui->plot->xAxis->setSubTicks(false);
                     ui->plot->xAxis->setTickLength(0, 4);
                     ui->plot->xAxis->setRange(0, 8);
                     ui->plot->xAxis->setBasePen(QPen(Qt::white));
                     ui->plot->xAxis->setTickPen(QPen(Qt::white));
                     ui->plot->xAxis->grid()->setVisible(true);
                     ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
                     ui->plot->xAxis->setTickLabelColor(Qt::white);
                     ui->plot->xAxis->setLabelColor(Qt::white);
                     ui->plot->xAxis->setLabel("horaire d'entrée");

                     // axe des ordonnées
                     ui->plot->yAxis->setRange(0,10);
                     ui->plot->yAxis->setPadding(5);
                     ui->plot->yAxis->setLabel("Statistiques");
                     ui->plot->yAxis->setBasePen(QPen(Qt::white));
                     ui->plot->yAxis->setTickPen(QPen(Qt::white));
                     ui->plot->yAxis->setSubTickPen(QPen(Qt::white));
                     ui->plot->yAxis->grid()->setSubGridVisible(true);
                     ui->plot->yAxis->setTickLabelColor(Qt::white);
                     ui->plot->yAxis->setLabelColor(Qt::white);
                     ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
                     ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

                     // ajout des données  (statistiques de l'horaire)//

                     QVector<double> PlaceData;
                     QSqlQuery q1("select horaire_entr from Tickets");
                     while (q1.next()) {
                                   int  nbr_fautee = q1.value(0).toInt();
                                   PlaceData<< nbr_fautee;
                                     }
                     amande->setData(ticks, PlaceData);

                     ui->plot->legend->setVisible(true);
                     ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
                     ui->plot->legend->setBrush(QColor(250, 255, 255, 255));
                     ui->plot->legend->setBorderPen(Qt::NoPen);
                     QFont legendFont = font();
                     legendFont.setPointSize(9);
                     ui->plot->legend->setFont(legendFont);
                     ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
                }

void MainWindow::on_on_pb_trier_ticket_clicked()
    {
        QString choix=ui->comboBox_7->currentText();
            if(choix=="par id")
            {
                QSqlQueryModel* test=T.triparid();
                QMessageBox msgBox;
                if(test){
                            msgBox.setText("tri avec succes");
                            ui->tab_ticket_2->setModel(T.triparid());
                        }
                            else
                            msgBox.setText(("echec"));

                            msgBox.exec();
                    }
            else if(choix=="par horaire")
            {
                QSqlQueryModel* test=T.triparhoraire_entr();
                QMessageBox msgBox;
                if(test){
                                msgBox.setText("tri avec succes");
                                ui->tab_ticket_2->setModel(T.triparhoraire_entr());
                            }
                                else
                                msgBox.setText(("echec"));

                                msgBox.exec();
            }
            else if(choix=="par prix")
            {
                QSqlQueryModel* test=T.triparhoraire_entr();
                QMessageBox msgBox;
                if(test){
                                msgBox.setText("tri avec succes");
                                ui->tab_ticket_2->setModel(T.triparprix());
                            }
                                else
                                msgBox.setText(("echec"));

                                msgBox.exec();
            }
            }

void MainWindow::on_ticketVIP_clicked()
 {
       ui->tab_ticket_2->setModel(T.ticketVIP());
  }

void MainWindow::on_pb_QR_code_clicked()
{
    Ticket T;
    if(ui->tab_ticket_2->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Erreur"),
        QObject::tr("Veuillez Choisir une ticket du Tableau.\n""Click Ok to exit."), QMessageBox::Ok);
    else
        {
        T.setid(ui->tab_ticket_2->model()->data(ui->tab_ticket_2->model()->index(ui->tab_ticket_2->currentIndex().row(),0)).toInt());
        T.sethoraire_entr(ui->tab_ticket_2->model()->data(ui->tab_ticket_2->model()->index(ui->tab_ticket_2->currentIndex().row(),1)).toInt());
        T.sethoraire_arr(ui->tab_ticket_2->model()->data(ui->tab_ticket_2->model()->index(ui->tab_ticket_2->currentIndex().row(),2)).toInt());
        T.setprix(ui->tab_ticket_2->model()->data(ui->tab_ticket_2->model()->index(ui->tab_ticket_2->currentIndex().row(),3)).toInt());

        QString  rawQr = "ID:%1 horaire_entr:%2 horaire_arr:%3 PRIX:%4 " ;
        rawQr = rawQr.arg(T.getid()).arg(T.gethoraire_entr()).arg(T.gethoraire_arr()).arg(T.getprix());
        QrCode qr = QrCode::encodeText(rawQr.toUtf8().constData(), QrCode::Ecc::HIGH);
        std::ofstream myfile;
                            myfile.open ("qrcode.svg") ;
                            myfile << qr.toSvgString(1);
                            myfile.close();
                            QSvgRenderer svgRenderer(QString("qrcode.svg"));
                            QPixmap pix( QSize(140, 140) );
                            QPainter pixPainter( &pix );
                            svgRenderer.render( &pixPainter );
                            ui->label_qrcode->setPixmap(pix);
                            int i=0;
                                      for(i=0;i<100;i=i+0.1){
                                           i++;
                                           ui->progressBar->setValue(i);
                                        }

                    }
}


/* void MainWindow::on_pb_QR_code_clicked()
{
    int tabeq=ui->tab_ticket_2->currentIndex().row();
            QVariant idd=ui->tab_ticket_2->model()->data(ui->tab_ticket_2->model()->index(tabeq,0));
            int idt= idd.toInt();
            QSqlQuery qry;
            qry.prepare("select * from Tickets where idt=:idt");
            qry.bindValue(":idt",idt);
            qry.exec();
            QString id,entr,arr,p;
            while(qry.next()){
                entr=qry.value(1).toInt();
                arr=qry.value(2).toInt();
                p=qry.value(3).toInt();

            }
            id=int(idt);
            id="idt: "+id+" entr: "+entr+" arr: "+arr+" p: "+p;
*/
            //QrCode qr = QrCode::encodeText(id.toUtf8().constData(), QrCode::Ecc::HIGH);

             //Read the black & white pixels
            //QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
        //    for (int y = 0; y < qr.getSize(); y++) {
           //     for (int x = 0; x < qr.getSize(); x++) {
             //       int color = qr.getModule(x, y);  // 0 for white, 1 for black
                  //   You need to modify this part
           //         if(color==0)
            //            im.setPixel(x, y,qRgb(254, 254, 254));
            //        else
           //             im.setPixel(x, y,qRgb(0, 0, 0));
          //      }
      //      }
      //     im=im.scaled(200,200);
       //     ui->qrlabel->setPixmap(QPixmap::fromImage(im));
       //    int i=0 ;
      //     for(i=0;i<100;i=i+0.1){
       //         i++;
        //        ui->progressBar->setValue(i);
            //}
//}
