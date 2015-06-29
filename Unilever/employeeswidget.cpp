#include "employeeswidget.h"
#include "ui_employeeswidget.h"

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

void EmployeesWidget::importEmployeesFromXls(QString filename) {
    ParseManager* p = new ParseManager(this, DBManager::getInstance()->connection);
    p->fileName = filename;
    QStandardItemModel* model = p->loadEmployeeListToModel();
    ui->tableView->setModel(model);
}

void EmployeesWidget::on_tableView_doubleClicked(const QModelIndex &index)
{
    QModelIndex idIndex = index.model()->index(index.row(), 0);
    QString id = index.model()->data(idIndex).toString();

    wnd = new PersonalCardWidget(id, this);
    wnd->show();
}

void EmployeesWidget::on_button_add_employee_clicked()
{

}


