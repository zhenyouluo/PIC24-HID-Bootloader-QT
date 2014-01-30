#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//------------------------------------------------------------------------------------------------------------//
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QMenu>

#include "updatescheduler.h"
#include "updateavailabledialog.h"

namespace Ui {
class MainWindow;
}
//------------------------------------------------------------------------------------------------------------//
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow   *ui;   

    QSystemTrayIcon  *Ico;
    TUpdateScheduler *UpdateScheduler;

    UpdateAvailableDialog *updateAvailableDialog;

    QMenu*   SystemTrayMenu;
protected:
     void changeEvent( QEvent * event );

private slots:
    void TrayIcoClick(QSystemTrayIcon::ActivationReason Reason);
    void NeedUpdate(QString AppFile, QString ReleaseNotes);
    void Exit();
};
//------------------------------------------------------------------------------------------------------------//
#endif // MAINWINDOW_H
