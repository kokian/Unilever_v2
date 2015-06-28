#include "skillstypewidget.h"
#include "ui_skillstypewidget.h"

SkillsTypeWidget::SkillsTypeWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SkillsTypeWidget)
{
    ui->setupUi(this);
}

SkillsTypeWidget::~SkillsTypeWidget()
{
    delete ui;
}
