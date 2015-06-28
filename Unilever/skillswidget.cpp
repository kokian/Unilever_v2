#include "skillswidget.h"
#include "ui_skillswidget.h"

SkillsWidget::SkillsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SkillsWidget)
{
    ui->setupUi(this);
}

SkillsWidget::~SkillsWidget()
{
    delete ui;
}
