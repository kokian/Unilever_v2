#include "employeeswidget.h"
#include "ui_employeeswidget.h"
#include "personalcardscreen.h"
#include "constants.h"
#include "dbmanager.h"

#include <QSqlTableModel>

EmployeesWidget::EmployeesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::employeesWidget)
{
    ui->setupUi(this);

    QSqlTableModel* employeeListModel = DBManager::getInstance()->initModel(ENT_EMPLOYEE);
    ui->tableView->setModel(employeeListModel);
    int columns = ui->tableView->horizontalHeader()->count();
    for (int c = 0; c < columns; c++) {
        ui->tableView->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
    }
}

EmployeesWidget::~EmployeesWidget()
{
    delete ui;
}

void EmployeesWidget::on_tableView_doubleClicked(const QModelIndex &index)
{
    QModelIndex idIndex = index.model()->index(index.row(), 0);
    QString id = index.model()->data(idIndex).toString();

    PersonalCardScreen wnd(id, this);
    wnd.show();

    // wnd.setModal(true);
    //wnd.exec();
}

void EmployeesWidget::on_button_add_employee_clicked()
{

}


