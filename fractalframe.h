#ifndef FRACTALFRAME_H
#define FRACTALFRAME_H

#include <QPointF>
#include <cmath>

class FractalFrame
{
public:
    FractalFrame();
    void updateFractalFrame(QPointF point);
    inline QPointF & topLeft()
    {
        return _topLeft;
    }

    inline void setTopLeft(const QPointF & topLeft)
    {
        _topLeft = topLeft;
    }

    inline QPointF & bottomRight()
    {
        return _bottomRight;
    }

    inline void setBottomRight(const QPointF & bottomRight)
    {
        _bottomRight = bottomRight;
    }

    inline double width()
    {
        return fabs(bottomRight().x() - topLeft().x());
    }

    inline double height()
    {
        return fabs(topLeft().y() - bottomRight().y());
    }

private:
    QPointF _topLeft, _bottomRight;

};

#endif // FRACTALFRAME_H
