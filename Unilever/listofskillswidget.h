#ifndef LISTOFSKILLSWIDGET_H
#define LISTOFSKILLSWIDGET_H

#include <QDialog>

namespace Ui {
class ListOfSkillsWidget;
}

class ListOfSkillsWidget : public QDialog
{
    Q_OBJECT

public:
    explicit ListOfSkillsWidget(QWidget *parent = 0);
    ~ListOfSkillsWidget();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::ListOfSkillsWidget *ui;
};

#endif // LISTOFSKILLSWIDGET_H
