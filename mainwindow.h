#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColor>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void levelChanged(int level);
    void segmentPixelSizeChanged(int segmentPixelSize);
    void penWidthChanged(int penWidth);
    void changeColorButtonClicked();
    
private:
    void updateColorWidget(QColor color);
    Ui::MainWindow *ui;
    QColor _currentColor;
};

#endif // MAINWINDOW_H
