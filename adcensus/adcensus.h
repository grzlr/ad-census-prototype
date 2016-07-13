#ifndef ADCENSUS_H
#define ADCENSUS_H

#include <QObject>
#include <QImage>
#include <QUrl>
#include "matrix.h"

class ADCensus : public QObject
{
    Q_OBJECT
public:
    explicit ADCensus(QObject *parent = 0);

signals:

public slots:
    void constructDisparityMap(QUrl leftImageUrl, QUrl rightImageUrl);

private:
    double costAD(QImage leftImage, QImage rightImage, int x, int y, int disparity);
    double costCensus(QImage leftImage, QImage rightImage, int x, int y, int disparity);
    double robust(double cost, double lambda);
};

#endif // ADCENSUS_H