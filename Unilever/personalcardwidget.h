#ifndef PERSONALCARDWIDGET_H
#define PERSONALCARDWIDGET_H

#include <QDialog>

namespace Ui {
class PersonalCardWidget;
}

class PersonalCardWidget : public QDialog
{
    Q_OBJECT

public:
    explicit PersonalCardWidget(QWidget *parent = 0);
    ~PersonalCardWidget();

private:
    Ui::PersonalCardWidget *ui;
};

#endif // PERSONALCARDWIDGET_H
