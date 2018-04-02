#include "chart.h"

Chart::Chart(QString m_title)
    : m_title("")
{
    m_chart = new QChart;
    chartView = new QChartView(m_chart);
    chartView->setMinimumSize(800, 600);
    m_series = new QLineSeries;
    m_chart->addSeries(m_series);
    axX = new QValueAxis;
    axX->setRange(0, m_range);
    axX->setLabelFormat("%g");
    axX->setTitleText("Time");
    axY = new QValueAxis;
    axY->setRange(-1, 1);
    m_chart->setAxisX(axX, m_series);
    m_chart->setAxisY(axY, m_series);
    m_chart->legend()->hide();
    m_chart->setTitle(m_title);
}
Chart::~Chart()
{

}

void Chart::update (double wartosc)
{
    draw(wartosc);
}
QChartView* Chart::getHandle()
{
    return chartView;
}
void Chart::draw (double wartosc)
{
    QVector<QPointF> oldPoints = m_series->pointsVector();
    QVector<QPointF> points;
    int resolution = 1;
    qint64 maxSize=1;
    if (oldPoints.count() < m_range) {
        points = m_series->pointsVector();
    } else {
        for (int i = 1; i < m_range; i++)
            points.append(QPointF(i - 1, oldPoints.at(i).y()));
    }

    qint64 size = points.count();
    for (int k = 0; k < maxSize/resolution; k++)
        points.append(QPointF(k + size, wartosc));
    m_series->replace(points);
    //if (size==m_range-1)         axX->setRange(++axMin, ++axMax);

}
QValueAxis* Chart::axisX()
{
    return axX;
}
QValueAxis* Chart::axisY()
{
    return axY;
}
