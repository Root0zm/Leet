#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTextStream>
#include "filelistwindow.h"
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
    void on_openPlaintText_clicked();
    void on_save1_clicked();
    void on_openCypher_clicked();
    void on_openCypherText_clicked();
    void on_save2_clicked();
    void on_openPlaint_clicked();
    void on_reset_clicked();
    void on_reset2_clicked();
    void on_swap_clicked();
    void on_swap2_clicked();
    void handleItemDoubleClicked(const QString &key, const QString &content, bool isEncrypted);

private:
    Ui::MainWindow *ui;

    // Các hàm mã hóa/giải mã
    QString encrypt(const QString &plaintext, const QString &key);
    QString decrypt(const QString &ciphertext, const QString &key);
};
#endif // MAINWINDOW_H
