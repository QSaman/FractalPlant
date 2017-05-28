#include "fractalframe.h"
#include "my_global.h"

FractalFrame::FractalFrame()
{
    setTopLeft(QPointF(inf, -inf));
    setBottomRight(QPointF(-inf, inf));
}

void FractalFrame::updateFractalFrame(QPointF point)
{
    if (l(point.x(), topLeft().x()))
        topLeft().setX(point.x());
    if (g(point.x(), bottomRight().x()))
        bottomRight().setX(point.x());
    if (point.y() < bottomRight().y())
        bottomRight().setY(point.y());
    if (point.y() > topLeft().y())
        topLeft().setY(point.y());
}
