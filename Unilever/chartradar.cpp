#include "chartradar.h"
#include <math.h>


ChartRadar::ChartRadar(QWidget *parent) : QGraphicsView(parent)
{
scene = new QGraphicsScene(this);

setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing);
color_num=0;
}

void ChartRadar::setIndicatorsList(QStringList _list)
{
indicatorsList =  _list;
amount_indicators = indicatorsList.size();
}

void ChartRadar::setHeader(QString _header)
{
    Header = _header;
}

void ChartRadar::setSize(int _sizeWdgt)
{
    if (_sizeWdgt==0) _sizeWdgt=300;

    sizeWidget   =  _sizeWdgt;
    sizeHeader   =  10*sizeWidget/100;
    sizeLegend   =  10*sizeWidget/100;
    sizeMargin   =  5*sizeWidget/100;
    sizeDiagramm =  70*sizeWidget/100;
    diagRad      =  sizeDiagramm/2;

    x0 = sizeWidget/2;
    y0 = sizeHeader+sizeLegend+sizeMargin+diagRad;

}

void ChartRadar::setGridScale(int _grid_scale)
{
    grid_scale=_grid_scale;
    grid_scale_step = diagRad/grid_scale;
}

void ChartRadar::drawGrid()
{
    for(int s=1; s <= grid_scale; s++){
        for (int r = 0; r < amount_indicators; r++ )
        {
            float angle = (3.1415926*(r*(360.0f/amount_indicators)-90))/180;
            float angle1 = (3.1415926*((r+1)*(360.0f/amount_indicators)-90))/180;


            float x = s*grid_scale_step*cos(angle);
            float y = s*grid_scale_step*sin(angle);
            float x1 = s*grid_scale_step*cos(angle1);
            float y1 = s*grid_scale_step*sin(angle1);

            scene->addLine(QLineF(x0+x,y0+y,x0+x1,y0+y1),QPen(Qt::black, 0.5));

            if (s==grid_scale)
                scene->addLine(QLineF(x0,y0,x+x0,y+y0),QPen(Qt::black, 0.5));

        }

    }

}

void ChartRadar::drawDiag()
{
    float maxValue=0;
    for (int l=0; l<radarsList.size();l++)
        for (int i=0; i<amount_indicators;i++)
        {
            float value = radarsList.at(l)->data.at(i);
            if (value>maxValue) { maxValue = value;}
        }

    float scale = diagRad/maxValue;

    for (int l=0; l<radarsList.size();l++)
    {
        QVector<QPointF> p;

        for (int i=0; i<amount_indicators;i++)
        {
            float angleD = i*(360.0f/amount_indicators)-90;
            float angleR = (3.14159*(angleD))/180;

            float d = radarsList.at(l)->data.at(i);

            float x = scale*d*cos(angleR);
            float y = scale*d*sin(angleR);

            p.push_back( QPointF( x+x0, y+y0 ));

        }

     QGraphicsPolygonItem *polygonItem = new QGraphicsPolygonItem(p,0);
     polygonItem->setPen(Qt::NoPen);
     polygonItem->setBrush(radarsList.at(l)->color);

     radarsList.at(l)->polygonItem = polygonItem;

     scene->addItem(polygonItem);

    }





}

void ChartRadar::drawHeader()
{
    scene->addRect(QRectF(0,0, sizeWidget, sizeHeader),QPen(Qt::darkGray, 1.5),Qt::gray);


    QGraphicsTextItem *h = new QGraphicsTextItem(Header);
    QFont fnt = QFont("Courier", sizeHeader/2, QFont::Normal);
    fnt.setStretch(QFont::SemiExpanded);
    h->setFont(fnt);

    int s = h->boundingRect().width();

    h->setPos(x0-s/2,  0);

    scene->addItem(h);
}

void ChartRadar::drawIndicators()
{
    for (int i = 0; i < amount_indicators; i++ )
    {
        float fntSize = 8;

        QString s = indicatorsList.at(i);

        QGraphicsTextItem *t = new QGraphicsTextItem(s);
        QFont fnt = QFont("Courier", fntSize, QFont::Normal);
        fnt.setStretch(QFont::SemiCondensed);
        t->setFont(fnt);

        float angleD = i*(360.0f/amount_indicators);
        float angleR = (3.14159*(angleD-90))/180;

        float posX_correcter;
        if (( 10 <= angleD) && (angleD <=170 ))
            {posX_correcter = 0;}
        else
        if (( 190 <= angleD) && (angleD <=350 ))
        {posX_correcter = t->boundingRect().width();}
        else
            {posX_correcter = t->boundingRect().width()/2;}


        float posY_correcter = t->boundingRect().height()/2;

        float x = 1.03*diagRad*cos(angleR)-posX_correcter;
        float y = 1.05*diagRad*sin(angleR)-posY_correcter;






        t->setPos(x0+x,y0+y);


        scene->addItem(t);

    }
}

void ChartRadar::drawLegend()
{
    int leg_count = radarsList.size();

    float s = sizeWidget/leg_count;

    float fntSize = 8;



    for(int i=0; i< leg_count;i++)
    {
        float   x = s/10 + (i/3)*s;
        float   y = sizeHeader + sizeLegend/8 + (i%3)*(fntSize + sizeLegend/8);


        scene->addRect(QRectF( x, y, fntSize*2, fntSize),
                       QPen(Qt::darkGray, 1.5),
                       radarsList.at(i)->color);


        QGraphicsTextItem *l = new QGraphicsTextItem(radarsList.at(i)->name);
        QFont fnt = QFont("Courier", fntSize, QFont::Normal);
        l->setFont(fnt);
        l->setPos(x+fntSize*3, y-fntSize);

        scene->addItem(l);
    }


}

bool ChartRadar::addData(QString _dataName,QList<float> _data, QColor _color)
{
    bool res = false;

    if (_data.size()!= amount_indicators) return res;


    Radar *r = new Radar();
    r->data =_data;
    r->name = _dataName;
    r->color= _color;
    radarsList<<r;
    res = true;

    return res;
}

bool ChartRadar::addData(QString _dataName,QList<float> _data)
{
    return addData( _dataName, _data,  getColor());
}

void ChartRadar::clearData()
{
    color_num=0;
    amount_indicators=0;
    indicatorsList.clear();

    for(int i=0;i< radarsList.size();i++)
        delete radarsList.at(i)->polygonItem;

    radarsList.clear();
}

void ChartRadar::draw()
{
    scene->clear();

    scene->setSceneRect(0, 0, sizeWidget, sizeWidget);

    /*QColor c1;
    c1.setRgb(150,150,255);
    QColor c2;
    c2.setRgb(230,230,255);*/

    QColor c1;
    c1.setRgb(90,165,90);
    QColor c2;
    c2.setRgb(180,255,180);

    QLinearGradient linearGradient(0, 0, sizeWidget, sizeWidget);
    linearGradient.setColorAt(0.0, c2);
   // linearGradient.setColorAt(0.5, c1);
    linearGradient.setColorAt(1.0, c1);

    setBackgroundBrush(linearGradient);

    setMinimumSize(sizeWidget,sizeWidget);

    drawHeader();


    drawDiag();

    drawIndicators();

    drawGrid();

    drawLegend();


    setScene(scene);
}

QColor ChartRadar::getColor()
{
    QColor c;
    switch (color_num) {
    case 0:
        c.setRgb(153,102,204);
        break;
    case 1:
        c.setRgb(102,153,102);
        break;
    case 2:
        c.setRgb(204,102,102);
        break;
    case 3:
        c.setRgb(255,204,153);
        break;
    case 4:
        c.setRgb(204,204,255);
        break;
    case 5:
        c.setRgb(153,204,255);
        break;
    case 6:
        c.setRgb(204,153,255);
        break;
    default:
        c.black();
        break;
    }

    color_num++;

    return c;
}

ChartRadar::~ChartRadar()
{
    delete scene;
}

void ChartRadar::resizeEvent(QResizeEvent *event)
{
    fitInView(0, 0, sizeWidget, sizeWidget,Qt::KeepAspectRatio);
    QGraphicsView::resizeEvent(event);
}






