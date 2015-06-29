#ifndef EMPLOYEESWIDGET_H
#define EMPLOYEESWIDGET_H

#include <QWidget>
#include <QSqlTableModel>
#include <QStandardItemModel>
#include <QSqlQuery>

#include "qchartviewer.h"
#include "personalcardwidget.h"
#include "constants.h"

namespace Ui {
class employeesWidget;
}

class EmployeesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeesWidget(QWidget *parent = 0);
    void importEmployeesFromXls(QString filename);
    ~EmployeesWidget();
private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_button_add_employee_clicked();

    void on_button_save_employee_clicked();

    void on_button_save_employee_pressed();

private:
    Ui::employeesWidget *ui;
    PersonalCardWidget *wnd;

    QSqlTableModel* db_model;
    QStandardItemModel* xls_model;
    MODEL_MODE mode;
    QSqlQuery* query;
};

#endif // EMPLOYEESWIDGET_H
