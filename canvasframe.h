#ifndef CANVASFRAME_H
#define CANVASFRAME_H

#include <QFrame>
#include <QPen>
#include <QColor>
#include "fractalplant.h"

class CanvasFrame : public QFrame
{
    Q_OBJECT
public:
    explicit CanvasFrame(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    
signals:
    
public slots:
    void setColor(QColor color);
    void penWidthChanged(int width);
    void levelChanged(int level);
    void segmentPixelSizeChanged(int segmentPixelSize);
    void setBackgroundColor(QColor color);
    void fractalColorChanged(QColor color);

private:
    FractalPlant _fractalPlant;
    QPen _pen;
    
};

#endif // CANVASFRAME_H
