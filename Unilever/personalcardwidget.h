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

    QChartViewer* stackRadarWidget;
    QChartViewer* drawStackRadar(QSqlTableModel *model);
    BaseChart* stackradar(int, const char **imageMap, QSqlTableModel *model);

    QChartViewer* statsRadarWidget;
    QChartViewer* drawStatsRadar(QSqlTableModel *model);
    BaseChart* statsradar(int, const char **imageMap, QSqlTableModel *model);

};

#endif // PERSONALCARDWIDGET_H
