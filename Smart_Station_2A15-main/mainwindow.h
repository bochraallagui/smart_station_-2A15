#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"client.h"
#include <QMainWindow>
#include"personnel.h"
#include "popup.h"
#include "chat.h"
#include "metro.h"
#include "station.h"
#include "trajet.h"
#include "ticket.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:




    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_modifier_clicked();
    void on_pb_trierclient_clicked();
    void on_pb_rechercherclient_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_pb_send_clicked();
    void on_pb_export_excel_clicked();




    void on_pb_tri_nom_clicked();
    void on_pb_rechercher_clicked();
    void on_pushButton_clicked();
    void on_chatBtn_clicked();
    void on_pb_modifier_2_clicked();
    void on_pb_supprimer_2_clicked();
    void  on_pb_ajouter_2_clicked();
    void on_tabWidget_currentChanged_2(int index);





    void on_ajouter_clicked();
    void on_pb_modifier_3_clicked();
    void on_pb_supprimer_3_clicked();
    void on_AFFECTER_clicked();
    void on_pb_trier_matricule_clicked();
    void on_pb_pdf_2_clicked();
    void on_pb_rechercher_2_clicked();
    void on_tabWidget_3_currentChanged(int index);



    //void on_pb_ajouter_3_clicked();

    void on_pb_ajouter_station_clicked();

    void on_pb_modifier_station_clicked();

    void on_pb_supprimer_station_clicked();

    void on_pb_recherche_clicked();

    void on_pb_tri_station_clicked();

    void on_pb_ajouter_trajet_clicked();

    void on_supprimer_clicked();

  //  void on_pushButton_clicked();

    void on_modifier_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_pushButton_trier_trajet_clicked();

    void on_pushButton_rechercher_trajet_clicked();

    void on_tabWidget_5_currentChanged(int index);

    void on_pushButton_exporter_trajet_clicked();

    void on_pushButton_qrcode_trajet_clicked();


    void on_pb_ajouter_4_clicked();
       void on_pb_supp_2_clicked();
        void on_pb_modifier_5_clicked();
        void on_on_pb_trier_ticket_clicked();
        void on_pb_recherche_ID_2_clicked();
       void on_pb_recherche_PRIX_2_clicked();
        void on_pb_recherche_horaire_entr_2_clicked();
        void on_pb_QR_code_clicked();
        void on_tabWidget_6_currentChanged(int index);
        void on_ticketVIP_clicked();
        void on_widget_4_customContextMenuRequested(const QPoint &pos);




        void on_gestionclient_clicked();

        void on_gestionstation_clicked();

        void on_gestionpersonnel_clicked();

        void on_gestionmetro_clicked();

        void on_gestiontrajet_clicked();

        void on_gestionticket_clicked();

private:
    Ui::MainWindow *ui;
     Client C;
     Personnel P ;
         Popup *popup;
         ChatMainWindow * chat ;
      Metro M ;
      Station S ;
      trajet *Etmp;
      Ticket T;
};
#endif // MAINWINDOW_H
