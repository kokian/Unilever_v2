#ifndef EMPLOYEESWIDGET_H
#define EMPLOYEESWIDGET_H

#include <QWidget>
#include <QSqlRelationalTableModel>

#include "qchartviewer.h"

namespace Ui {
class employeesWidget;
}

class EmployeesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeesWidget(QWidget *parent = 0);
    ~EmployeesWidget();
private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_button_add_employee_clicked();

private:
    Ui::employeesWidget *ui;
};

#endif // EMPLOYEESWIDGET_H
