#ifndef POSITIONWIDGET_H
#define POSITIONWIDGET_H

#include <QDialog>

namespace Ui {
class PositionWidget;
}

class PositionWidget : public QDialog
{
    Q_OBJECT

public:
    explicit PositionWidget(QWidget *parent = 0);
    ~PositionWidget();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::PositionWidget *ui;
};

#endif // POSITIONWIDGET_H
