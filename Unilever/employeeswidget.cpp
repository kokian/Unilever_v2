#include "employeeswidget.h"
#include "ui_employeeswidget.h"

#include <QMessageBox>
#include <QBrush>

#include "constants.h"
#include "dbmanager.h"

EmployeesWidget::EmployeesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::employeesWidget)
{
    ui->setupUi(this);

    db_model = DBManager::getInstance()->initModel(ENT_EMPLOYEE);
    ui->tableView->setModel(db_model);
    mode = MODE_DB;
    int columns = ui->tableView->horizontalHeader()->count();
    for (int c = 0; c < columns; c++) {
        ui->tableView->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
    }
    query = new QSqlQuery(DBManager::getInstance()->connection);
}

EmployeesWidget::~EmployeesWidget()
{
    if(db_model) {
        delete db_model;
    }if(xls_model) {
        delete xls_model;
    }
    delete query;
    delete ui;
}

void EmployeesWidget::importEmployeesFromXls(QString filename) {
    ParseManager* p = new ParseManager(this, DBManager::getInstance()->connection);
    p->fileName = filename;
    xls_model = p->loadEmployeeListToModel();
    ui->tableView->setModel(xls_model);
    mode = MODE_XLS;
}

void EmployeesWidget::on_tableView_doubleClicked(const QModelIndex &index)
{
    switch(mode) {
    case MODE_XLS:
    {
        QMessageBox msgBox;
        msgBox.setText("You have unsaved changes. Save or discard changes at first.");
        msgBox.exec();
        break;
    }
    case MODE_DB:
    {
        QModelIndex idIndex = index.model()->index(index.row(), 0);
        QString id = index.model()->data(idIndex).toString();
        wnd = new PersonalCardWidget(id, this);
        wnd->show();
        break;
    }
    default:
        break;
    }
}

void EmployeesWidget::on_button_add_employee_clicked()
{

}



void EmployeesWidget::on_button_save_employee_clicked()
{
    if(mode != MODE_XLS) {
        return;
    }
    for (int row = 0; row < xls_model->rowCount(); row++) {
        QVariant value = xls_model->data(xls_model->index(row, 6), Qt::BackgroundRole);
        if(!value.isValid()) {
            continue;
        }
        QBrush code_brush = value.value<QBrush>();
        bool isNewEmployee = code_brush.color() == Qt::gray;
        if(isNewEmployee) {
            query->prepare("INSERT INTO ul_employees (name_leg, job_title, position_title, department, hire_date, code, name, reported) "
                           "VALUES(?, ?, ?, ?, ?, ?, ?, ?);");
            for(int col = 0; col < xls_model->columnCount(); col++) {
                query->addBindValue(xls_model->item(row, col)->data());
            }
            if (!query->exec()) {
                qDebug() << "Unable to make insert operation" << query->lastError();
            }
        } else {
            query->prepare("UPDATE ul_employees "
                           "SET name_leg=?, "
                           "job_title=?, "
                           "position_title=?,"
                           "department=?, "
                           "hire_date=?, "
                           "code=?, "
                           "name=?, "
                           "reported=? "
                           "WHERE code=?;");
            for(int col = 0; col < xls_model->columnCount(); col++) {
                query->addBindValue(xls_model->item(row, col)->data());
            }
            query->addBindValue(xls_model->item(row, 6)->data());
            if (!query->exec()) {
                qDebug() << "Unable to make insert operation" << query->lastError();
            }
        }
    }
    db_model->select();
    ui->tableView->setModel(db_model);
    mode = MODE_DB;
}

void EmployeesWidget::on_button_save_employee_pressed()
{

}
