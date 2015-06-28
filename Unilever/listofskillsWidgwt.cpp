#include "listofskillswidget.h"
#include "ui_listofskills.h"

ListOfSkills::ListOfSkills(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListOfSkills)
{
    ui->setupUi(this);
}

ListOfSkills::~ListOfSkills()
{
    delete ui;
}
