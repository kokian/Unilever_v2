#include "employeeswidget.h"
#include "ui_employeeswidget.h"
#include "personalcardwidget.h"

EmployeesWidget::EmployeesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::employeesWidget)
{
    ui->setupUi(this);
}

EmployeesWidget::~EmployeesWidget()
{
    delete ui;
}

void EmployeesWidget::on_tableView_doubleClicked(const QModelIndex &index)
{
    PersonalCardWidget wnd(this);
    wnd.setModal(true);
    wnd.exec();
}

void EmployeesWidget::on_button_add_employee_clicked()
{
    PersonalCardWidget wnd(this);
    wnd.setModal(true);
    wnd.exec();
}
