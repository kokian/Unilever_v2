#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "dbmanager.h"
#include "constants.h"
#include "parsemanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_Close_triggered();

    void on_action_about_triggered();

    void on_action_dictonary_positions_triggered();

    void on_action_list_of_skills_triggered();

    void on_action_skill_type_triggered();

    void on_action_skill_level_triggered();

    void on_action_Import_triggered();

private:

    DBManager* dbManager;
    ParseManager* parseManager;
    Ui::MainWindow *ui;

    QWidget* createView(VIEW_NAME vName);


};

#endif // MAINWINDOW_H
