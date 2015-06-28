#ifndef SKILLSLEVELWIDGET_H
#define SKILLSLEVELWIDGET_H

#include <QDialog>

namespace Ui {
class SkillsLevelWidget;
}

class SkillsLevelWidget : public QDialog
{
    Q_OBJECT

public:
    explicit SkillsLevelWidget(QWidget *parent = 0);
    ~SkillsLevelWidget();

private:
    Ui::SkillsLevelWidget *ui;
};

#endif // SKILLSLEVELWIDGET_H
