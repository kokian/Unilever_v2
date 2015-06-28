#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "aboutdialog.h"
#include "skillstypewidget.h"
#include "skillslevelwidget.h"
#include "positionwidget.h"
#include "listofskillswidget.h"

#include "employeeswidget.h"
#include "skillswidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //dbManager = new DBManager("188.166.126.89", 5432, "QPSQL", "postgres", "postgres", "74507", this);
    dbManager = DBManager::getInstance();
    dbManager->connect();

    QString titles[] = {"Сотрудники", "Навыки"};//, "Personal Card", "Personal Radar", "Personal Plan"};

    for(int i = 0; i < 2; i++) {//(int)VIEW_COUNT; i++) {
        QWidget* wdg = this->createView((VIEW_NAME)i);
        ui->tabWidget->addTab(wdg,titles[i]);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

QWidget* MainWindow::createView(VIEW_NAME vName) {
    QWidget* view = 0;
    switch(vName) {
    case VIEW_EMPLOYEES:
        view = new EmployeesWidget(this);
        break;
    case VIEW_SKILLS:
        view = new SkillsWidget(this);
        break;
    default:
        view = new QWidget();
        break;
    }
    return view;
}


void MainWindow::on_action_Close_triggered()
{
    close();

}

void MainWindow::on_action_about_triggered()
{
    aboutDialog wnd(this);
    wnd.setModal(true);
    wnd.exec();
}

void MainWindow::on_action_dictonary_positions_triggered()
{
    PositionWidget wnd(this);
    wnd.setModal(true);
    wnd.exec();
}

void MainWindow::on_action_list_of_skills_triggered()
{
    ListOfSkillsWidget wnd(this);
    wnd.setModal(true);
    wnd.exec();
}

void MainWindow::on_action_skill_type_triggered()
{
    SkillsTypeWidget wnd(this);
    wnd.setModal(true);
    wnd.exec();
}

void MainWindow::on_action_skill_level_triggered()
{
    SkillsLevelWidget wnd(this);
    wnd.setModal(true);
    wnd.exec();
}
