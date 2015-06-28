#include "personalcardwidget.h"
#include "ui_personalcardwidget.h"

#include "dbmanager.h"
#include <QSqlTableModel>
#include <QLayout>

PersonalCardWidget::PersonalCardWidget(QString& personal_id,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PersonalCardWidget)
{
    ui->setupUi(this);

    QSqlTableModel* model = DBManager::getInstance()->initModel(ENT_EMPLOYEES_X_SKILLS);
    model->setFilter(QString("employee_id='%1'").arg(personal_id));    
    model->select();
    ui->personalSkillsTableView->setModel(model);

    QLayout* radarLayout = new QHBoxLayout();
    radarLayout->addWidget(this->drawRadar(model));
    ui->label->setLayout(radarLayout);
}

PersonalCardWidget::~PersonalCardWidget()
{
    delete ui;
}

QChartViewer* PersonalCardWidget::drawRadar(QSqlTableModel *model) {
    QChartViewer* chartViewer = new QChartViewer();
    const char *imageMap = 0;
    chartViewer->setChart(this->stackradar(0, &imageMap, model));
    chartViewer->setImageMap(imageMap);
    return chartViewer;
}

BaseChart* PersonalCardWidget::stackradar(int, const char **imageMap, QSqlTableModel *model)
{
    // The data for the chart
    //double data0[] = {100, 100, 100, 100, 100, 100};
    //double data1[] = {90, 85, 85, 80, 70, 60};
    //double data2[] = {80, 65, 65, 75, 45, 30};
    //model->setFilter("unknown_id=1");
    int count = model->rowCount();
    double** data = new double*[6];
    for(int j = 0; j < 6; j++)
        data[j] = new double[count];
    char** labels = new char*[count];

    int skill_index = model->fieldIndex("description");
    int unknown_index = model->fieldIndex("unknown_id");
    int target_index = model->fieldIndex("target");
    int m2013_H2_index = model->fieldIndex("m2013_H2");
    int m2014_H1_index = model->fieldIndex("m2014_H1");
    int m2014_H2_index = model->fieldIndex("m2014_H2");
    int m2015_H1_index = model->fieldIndex("m2015_H1");
    int m2015_H2_index = model->fieldIndex("m2015_H2");

    qDebug() << count;

    for(int i = 0; i < count; i++) {
        QSqlRecord rec = model->record(i);
        data[0][i] = rec.value(target_index).toDouble();
        data[1][i] = rec.value(m2013_H2_index).toDouble();
        data[2][i] = rec.value(m2014_H1_index).toDouble();
        data[3][i] = rec.value(m2014_H2_index).toDouble();
        data[4][i] = rec.value(m2015_H1_index).toDouble();
        data[5][i] = rec.value(m2015_H2_index).toDouble();

        const char* src = rec.value(skill_index).toString().toStdString().c_str();
        labels[i] = new char[strlen(src)];
        strcpy(labels[i], src);

        qDebug() << labels[i] << ":" << data[0][i] << "," << data[1][i] << "," << data[2][i] << ","
                               << data[3][i] << "," << data[4][i] << "," << data[5][i];
    }


    // The labels for the chart
    /*
    const char *labels[] = {"Population<*br*><*font=arial.ttf*>6 millions",
        "GDP<*br*><*font=arial.ttf*>120 billions",
        "Export<*br*><*font=arial.ttf*>25 billions",
        "Import<*br*><*font=arial.ttf*>24 billions",
        "Investments<*br*><*font=arial.ttf*>20 billions",
        "Others<*br*><*font=arial.ttf*>10 billions"};
    */
    // Create a PolarChart object of size 480 x 460 pixels. Set background color to
    // silver, with 1 pixel 3D border effect
    PolarChart *c = new PolarChart(500, 500, Chart::silverColor(), 0x000000, 1);

    // Add a title to the chart using 15 pts Times Bold Italic font. The title text
    // is white (ffffff) on a deep green (008000) background
    c->addTitle("Skills Radar", "timesbi.ttf", 15, 0xffffff)->setBackground(
        0x008000);

    // Set plot area center at (240, 270), with 150 pixels radius
    c->setPlotArea(275, 300, 150);

    // Use 1 pixel width semi-transparent black (c0000000) lines as grid lines
    c->setGridColor(0xc0000000, 1, 0xc0000000, 1);

    // Add a legend box at top-center of plot area (240, 35) using horizontal layout.
    // Use 10 pts Arial Bold font, with silver background and 1 pixel 3D border
    // effect.
    LegendBox *b = c->addLegend(240, 35, false, "arialbd.ttf", 8);
    b->setAlignment(Chart::TopCenter);
    b->setBackground(Chart::silverColor(), Chart::Transparent, 1);

    // Add area layers of different colors to represent the data
    c->addAreaLayer(DoubleArray(data[0], count),
        0xcc8880, "Target");
    c->addAreaLayer(DoubleArray(data[1], count),
        0xffd080, "2013_H2");
    c->addAreaLayer(DoubleArray(data[2], count),
        0xa0bce0, "2014_H1");
    c->addAreaLayer(DoubleArray(data[3], count),
        0xc7f5a0, "2014_H2");
    c->addAreaLayer(DoubleArray(data[4], count),
        0x81daf0, "2015_H1");
    c->addAreaLayer(DoubleArray(data[5], count),
        0xe429c0, "2015_H2");

    // Set the labels to the angular axis as spokes.
    c->angularAxis()->setLabels(StringArray(labels, count));
    c->angularAxis()->setLabelStyle("bold", 7);

    // Set radial axis from 0 - 100 with a tick every 20 units
    c->radialAxis()->setLinearScale(0, 5, 1);

    // Just show the radial axis as a grid line. Hide the axis labels by setting the
    // label color to Transparent
    c->radialAxis()->setColors(0xc0000000, Chart::Transparent);

    // Output the chart
    c->makeChart();

    //include tool tip for the chart
    *imageMap = c->getHTMLImageMap("clickable", "",
        "title='Current {label}: {value}% in {dataSetName}'");

    return c;
}
