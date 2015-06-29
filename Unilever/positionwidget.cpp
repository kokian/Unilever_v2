#include "positionwidget.h"
#include "ui_positionwidget.h"

#include "dbmanager.h"
#include "constants.h"

PositionWidget::PositionWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PositionWidget)
{
    ui->setupUi(this);
    //ui->tableView->setModel();
}

PositionWidget::~PositionWidget()
{
    delete ui;
}

void PositionWidget::on_pushButton_2_clicked()
{
    close();
}
