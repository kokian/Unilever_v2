#include "skillslevelwidget.h"
#include "ui_skillslevelwidget.h"

SkillsLevelWidget::SkillsLevelWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SkillsLevelWidget)
{
    ui->setupUi(this);
}

SkillsLevelWidget::~SkillsLevelWidget()
{
    delete ui;
}
