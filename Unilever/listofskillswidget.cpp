#include "listofskillswidget.h"
#include "ui_listofskillswidget.h"

ListOfSkillsWidget::ListOfSkillsWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListOfSkillsWidget)
{
    ui->setupUi(this);
}

ListOfSkillsWidget::~ListOfSkillsWidget()
{
    delete ui;
}
