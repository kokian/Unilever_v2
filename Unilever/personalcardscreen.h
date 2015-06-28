#ifndef PERSONALCARDSCREEN_H
#define PERSONALCARDSCREEN_H

#include <QWidget>
#include "qchartviewer.h"
#include <QSqlTableModel>

namespace Ui {
class PersonalCardScreen;
}

class PersonalCardScreen : public QWidget
{
    Q_OBJECT

public:
    explicit PersonalCardScreen(QString& personal_id,QWidget *parent = 0);
    ~PersonalCardScreen();

private:
    Ui::PersonalCardScreen *ui;
    QChartViewer* radarWidget;
    QChartViewer* drawRadar(QSqlTableModel *model);
    BaseChart* stackradar(int, const char **imageMap, QSqlTableModel *model);
};

#endif // PERSONALCARDSCREEN_H
