/*
 *
 * For more information see http://en.wikipedia.org/wiki/L-system#Example_7:_Fractal_plant
 *
 */

#ifndef FRACTALPLANT_H
#define FRACTALPLANT_H

#include <QString>
#include <QVector>
#include <QPointF>

#include "fractalframe.h"

class FractalPlant
{
public:
    FractalPlant();    
    void generatePoints();

//setters & getters
    inline const QString & LSystem()    {return _LSystem;}
    inline int level()  {return _level;}
    inline void setLevel(int level) {_level = level;}
    inline FractalFrame & fractalFrame()  {return _fractalFrame;}
    inline QVector< QVector<QPointF> > & points()  {return _points;}
    inline double segmentPixelSize()   {return _segmentPixelSize;}
    inline void setSegmentPixelSize(double segmentPixelSize)    {_segmentPixelSize = segmentPixelSize;}
    inline QPointF startPoint() {return _startPoint;}
    inline void setStartPoint(QPointF startPoint)   {_startPoint = startPoint;}

private:
    //**************************Private classes**************************************
    class StackFrame
    {
    public:
        StackFrame(QPointF point, double angle)  {setPoint(point); setAngle(angle);}
        StackFrame()    {}
        //setters & getters
        inline QPointF point()   {return _point;}
        inline void setPoint(QPointF point)   {_point = point;}
        inline double angle()   {return _angle;}
        inline void setAngle(double angle)  {_angle = angle;}
    private:
        QPointF _point;
        double _angle;
    };
    //***********************End of Private classes***********************************

    QString generateLSystem(QString partialLSystem, int level);
    void renderLSystem();
    void addPointtoCurrentSet(QPointF point);
    void addPointtoNewSet(QPointF point);
    void clear();

//setters & getters
    inline void setLSystem(QString LSystem) {_LSystem = LSystem;}
    inline void setFractalFrame(FractalFrame fractalFrame)  {_fractalFrame = fractalFrame;}

    const QString Xrule;
    const QString Frule;
    QString _LSystem;
    QVector< QVector<QPointF> > _points;
    int _level;
    FractalFrame _fractalFrame;
    double _segmentPixelSize;
    QPointF _startPoint;
};

#endif // FRACTALPLANT_H
