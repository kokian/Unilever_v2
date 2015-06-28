#ifndef PERSONALCARDWIDGET_H
#define PERSONALCARDWIDGET_H

#include <QMainWindow>
#include "qchartviewer.h"
#include <QSqlTableModel>

namespace Ui {
class PersonalCardWidget;
}

class PersonalCardWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit PersonalCardWidget(QString& personal_id,QWidget *parent = 0);
    ~PersonalCardWidget();

private:
    Ui::PersonalCardWidget *ui;
    QChartViewer* radarWidget;
    QChartViewer* drawRadar(QSqlTableModel *model);
    BaseChart* stackradar(int, const char **imageMap, QSqlTableModel *model);
};

#endif // PERSONALCARDWIDGET_H
