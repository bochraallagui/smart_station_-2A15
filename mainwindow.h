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
    void on_pb_ajouter_clicked();
    void on_pb_supp_clicked();
    void on_pb_modifier_clicked();
    
private:
    Ui::MainWindow *ui;
    Ticket T;
};

#endif // MAINWINDOW_H
