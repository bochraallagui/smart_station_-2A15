#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ticket.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_4_clicked();
    void on_pb_supp_2_clicked();
    void on_pb_modifier_5_clicked();
    void on_on_pb_trier_ticket_clicked();
    void on_pb_recherche_ID_2_clicked();
   void on_pb_recherche_PRIX_2_clicked();
    void on_pb_recherche_horaire_entr_2_clicked();
    void on_pb_QR_code_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_ticketVIP_clicked();

private:
    Ui::MainWindow *ui;
    Ticket T;
};

#endif // MAINWINDOW_H
