#ifndef SKILLSTYPEWIDGET_H
#define SKILLSTYPEWIDGET_H

#include <QDialog>

namespace Ui {
class SkillsTypeWidget;
}

class SkillsTypeWidget : public QDialog
{
    Q_OBJECT

public:
    explicit SkillsTypeWidget(QWidget *parent = 0);
    ~SkillsTypeWidget();

private:
    Ui::SkillsTypeWidget *ui;
};

#endif // SKILLSTYPEWIDGET_H
