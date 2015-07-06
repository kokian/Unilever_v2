#ifndef PERSONALCARDWIDGET_H
#define PERSONALCARDWIDGET_H

#include <QMainWindow>
#include "qchartviewer.h"
#include <QSqlTableModel>
#include "chartradar.h"

namespace Ui {
class PersonalCardWidget;
}

class PersonalCardWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit PersonalCardWidget(QString& personal_id,QWidget *parent = 0);
    ~PersonalCardWidget();

private slots:
    void on_changePillarComboBox_activated(const QString &arg1);

private:
    Ui::PersonalCardWidget *ui;

    ChartRadar *CR_avg;
    ChartRadar *CR_wcm;

    ChartRadar* drawAvgRadar(QSqlTableModel *model);

    void createInfoTableView();

    QChartViewer* stackRadarWidget;
    QChartViewer* drawStackRadar(QSqlTableModel *model);
    BaseChart* stackradar(int, const char **imageMap, QSqlTableModel *model);

    QChartViewer* statsRadarWidget;
    QChartViewer* drawStatsRadar(QSqlTableModel *model);
    BaseChart* statsradar(int, const char **imageMap, QSqlTableModel *model);

};

#endif // PERSONALCARDWIDGET_H
