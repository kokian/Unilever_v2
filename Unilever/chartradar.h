#ifndef CHARTRADAR_H
#define CHARTRADAR_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

class Radar
{
    public:
    QList<float> data;
    QString name;
    QColor color;
    QGraphicsPolygonItem *polygonItem;
};

class ChartRadar : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ChartRadar(QWidget *parent = 0);

    void setHeader(QString _header);
    void setSize(int _diagSize);
    void setGridScale(int _grid_scale);
    void setIndicatorsList(QStringList _list);

    bool addData(QString _dataName,QList<float> _data);
    bool addData(QString _dataName,QList<float> _data, QColor _color);

    void draw();
    void clearData();


    ~ChartRadar();

protected:
    void resizeEvent(QResizeEvent *event);

private:
    QString Header;

    float sizeHeader;
    float sizeLegend;
    float sizeDiagramm;
    float sizeWidget;
    float sizeMargin;
    float x0,y0;
    float diagRad;

    int     amount_indicators;
    int     grid_scale;
    float   grid_scale_step;

    QList<Radar* > radarsList;

    QStringList indicatorsList;

    QGraphicsScene *scene;

    void drawHeader();
    void drawGrid();
    void drawDiag();
    void drawIndicators();
    void drawLegend();

    int color_num;
    QColor getColor();


signals:

public slots:
};




#endif // CHARTRADAR_H
