#ifndef SKILLSWIDGET_H
#define SKILLSWIDGET_H

#include <QWidget>

namespace Ui {
class SkillsWidget;
}

class SkillsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SkillsWidget(QWidget *parent = 0);
    ~SkillsWidget();

private:
    Ui::SkillsWidget *ui;
};

#endif // SKILLSWIDGET_H
