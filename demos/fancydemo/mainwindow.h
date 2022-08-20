#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qcanpool/fancywindow.h"

QCANPOOL_USE_NAMESPACE

class QActionGroup;

class MainWindow : public FancyWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    void createWindow();
    void createQuickAccessBar();
    void createMenuBar();
    void createSystemMenu();

private:
    void addThemeStyleItem(QActionGroup *group, QAction *action, const QString &qss);
    void setThemeStyle(const QString &style);
    void addWindowStyleItem(QActionGroup *group, QAction *action, int style);

private slots:
    void slotNew();
    void slotChangeThemeStyle();
    void slotChangeWindowStyle();
};
#endif // MAINWINDOW_H
