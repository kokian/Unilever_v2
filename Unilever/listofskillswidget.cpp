#include "listofskillswidget.h"
#include "ui_listofskillswidget.h"
#include "dbmanager.h"
#include "constants.h"

ListOfSkillsWidget::ListOfSkillsWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListOfSkillsWidget)
{
    ui->setupUi(this);

    ui->tableView->setModel(DBManager::getInstance()->initModel(ENT_SKILLS));
}

ListOfSkillsWidget::~ListOfSkillsWidget()
{
    delete ui;
}

void ListOfSkillsWidget::on_pushButton_2_clicked()
{
    close();
}
