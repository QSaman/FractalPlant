#include "canvasframe.h"
#include <QPainter>
#include <QColor>
#include <QDebug>

#include "my_global.h"

CanvasFrame::CanvasFrame(QWidget *parent) :
    QFrame(parent)
{
    setColor(QColor(0, 80, 0));
    setBackgroundColor(Qt::white);
    _fractalPlant.setSegmentPixelSize(1);
    _fractalPlant.setStartPoint(QPointF(0.0, height()));
    _pen.setWidth(0);
    _pen.setCosmetic(true);
    _fractalPlant.setLevel(1);
    _fractalPlant.generatePoints();
}

void CanvasFrame::setBackgroundColor(QColor color)
{
    QPalette palette;
    palette.setColor(QPalette::Background, color);
    setAutoFillBackground(true);
    setPalette(palette);
}

void CanvasFrame::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(_pen);
    /*
     * For determining scaling factor, first we should compare width() / height() and kochFrame.width() / kochFrame.height().
     * Suppose A = width() / height() and B = kochFrame.width() / kochFrame.height() and
     * C = width() * kochFrame.height() and D = height() * kochFrame.width():
     * 1) C = D => A = B => scalingFactor = 1
     * 2) C > D => A > B => kochFrame.height() * scalingFactor = height() => scalingFactor = height() / kochFrame.height()
     * 3) C < D => A < B => kochFrame.width() * scalingFactor = width() => scalingFactor = width() / kochFrame.width()
     *
     * Consider below mathmatics facts for understanding formulas:
     * if (A / B) > (A / C) => B < C (used in formula 3)
     * if (A / B) > (C / B) => A > C (used in formula 2)
     */
    double scale;
    double diff = width() * _fractalPlant.fractalFrame().height() - _fractalPlant.fractalFrame().width() * height();
    if (e(diff, 0.0))
        scale = 1.0;

    else if (g(diff, 0))
        scale = height() / (_fractalPlant.fractalFrame().height());
    else
        scale = width() / _fractalPlant.fractalFrame().width();

    QPointF middle = (_fractalPlant.fractalFrame().topLeft() + _fractalPlant.fractalFrame().bottomRight()) * scale / 2.0;
    painter.translate(width() / 2.0 - middle.x(), height() / 2.0 - middle.y());
    painter.scale(scale, scale);
    for (int i = 0; i < _fractalPlant.points().size(); ++i)
    {
        int len = _fractalPlant.points()[i].size() - 1;
        if (len <= 0)
            continue;
        for (int j = 0; j < len; ++j)
            painter.drawLine(_fractalPlant.points()[i][j], _fractalPlant.points()[i][j + 1]);
    }

}

void CanvasFrame::setColor(QColor color)
{
    _pen.setColor(color);
    update();
}
void CanvasFrame::penWidthChanged(int width)
{
    _pen.setWidth(width);
    _pen.setCosmetic(true);
    update();
}
void CanvasFrame::levelChanged(int level)
{
    _fractalPlant.setLevel(level);
    _fractalPlant.generatePoints();
    update();
}

void CanvasFrame::segmentPixelSizeChanged(int segmentPixelSize)
{
    _fractalPlant.setSegmentPixelSize(segmentPixelSize);
    _fractalPlant.generatePoints();
    update();
}

void CanvasFrame::fractalColorChanged(QColor color)
{
    _pen.setColor(color);
    update();
}
