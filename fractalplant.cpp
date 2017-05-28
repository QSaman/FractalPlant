#include "fractalplant.h"
#include <QStack>
#include <QDebug>
#include <cmath>
#include "my_global.h"

FractalPlant::FractalPlant() : Xrule("F-[[X]+X]+F[+FX]-X"), Frule("FF")
{
    setSegmentPixelSize(70);
    setStartPoint(QPointF(0.0, 0.0));
}

QString FractalPlant::generateLSystem(QString partialLSystem, int level)
{
    if (level <= 0)
        return partialLSystem;
    int i;
    for (i = 0; i < partialLSystem.length() && partialLSystem[i] != 'X' && partialLSystem[i] != 'F'; ++i);
    if (i >= partialLSystem.length())
        return partialLSystem;
    QString rule = (partialLSystem[i] == 'X' ? generateLSystem(Xrule, level - 1) :
                    generateLSystem(Frule, level - 1));
    return (partialLSystem.mid(0, i) + rule +
            generateLSystem(partialLSystem.mid(i + 1), level));
}

void FractalPlant::clear()
{
    setFractalFrame(FractalFrame());
    _points.clear();
    setLSystem("");
}


void FractalPlant::generatePoints()
{
    clear();
    int l = level();
    setLSystem(generateLSystem("X", l));
    renderLSystem();
}

void FractalPlant::renderLSystem()
{
    QStack<StackFrame> stack;
    int i;
    QPointF point = startPoint();
    double angle = degreeToRadian(45.0);
    addPointtoNewSet(point);
    const QString & lsystem = LSystem();
    for (i = 0; i < lsystem.length(); ++i)
    {
        if (lsystem[i] == '[')
            stack.push(StackFrame(point, angle));
        else if (lsystem[i] == ']')
        {
            StackFrame stackFrame = stack.pop();
            addPointtoNewSet(stackFrame.point());
            point = stackFrame.point();
            angle = stackFrame.angle();
        }
        else if (lsystem[i] == 'F')
        {
            point.setX(point.x() + segmentPixelSize() * cos(angle));
            point.setY(point.y() - segmentPixelSize() * sin(angle));    //There is subtraction because y axis is downward
            addPointtoCurrentSet(point);
        }
        else if (lsystem[i] == '+')
            angle -= degreeToRadian(25.0);
        else if (lsystem[i] == '-')
            angle += degreeToRadian(25.0);
    }
}

void FractalPlant::addPointtoCurrentSet(QPointF point)
{
    fractalFrame().updateFractalFrame(point);
    points().back().push_back(point);
}

void FractalPlant::addPointtoNewSet(QPointF point)
{
    fractalFrame().updateFractalFrame(point);
    points().push_back(QVector<QPointF>(1, point));
}


