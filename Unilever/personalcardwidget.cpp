#include "personalcardwidget.h"
#include "ui_personalcardwidget.h"

PersonalCardWidget::PersonalCardWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonalCardWidget)
{
    ui->setupUi(this);
}

PersonalCardWidget::~PersonalCardWidget()
{
    delete ui;
}
