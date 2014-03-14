#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QMenu>

#include <QtWidgets/QLabel>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include <QtConcurrent/QtConcurrentRun>

#include "updatescheduler.h"
#include "updateavailabledialog.h"
#include "aboutappdialog.h"
#include "HIDBootloader/Bootloader.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow   *ui;

    Bootloader  *bootloader;

    QString fileName;

    QSystemTrayIcon  *Ico;
    TUpdateScheduler *UpdateScheduler;

    UpdateAvailableDialog *updateAvailableDialog;
    AboutAppDialog        *aboutAppDialog;

    QMenu*   SystemTrayMenu;
    QFuture<void> future;

    QAction* ShowHideAction;
    QAction* checkUpdateAction;
    QAction* checkUploadFirmware;
    QAction* aboutVikingOneAction;
    QAction* quitAction;

    void uploadFirmware(unsigned char range);

protected:
     void changeEvent(QEvent* event);

private slots:
    void TrayIcoClick(QSystemTrayIcon::ActivationReason Reason);
    void ShowOrHideForm();
    void ShowAboutVikingOneWindow();
    void Exit();

    void onUploadFirmware();
    void NeedUpdate(QString AppFile, QString ReleaseNotes);    


    /* Bootloader event */
    void setConnected(bool enable);
    void setBootloadEnabled(bool enable);
    void setBootloadBusy(bool busy);
    void updateProgressBar(int newValue);
    void onMessage(Bootloader::MessageType type, QString value);
    void onMessageClear();

    void onReadComplete();
    void onWriteComplete();

    void on_WriteRunePackBtn_clicked();
};

#endif // MAINWINDOW_H