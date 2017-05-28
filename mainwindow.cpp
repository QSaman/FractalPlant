#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _currentColor(QColor(0, 80, 0))
{
    ui->setupUi(this);

    connect(ui->levelHorizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(levelChanged(int)));
    connect(ui->PixelHorizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(segmentPixelSizeChanged(int)));
    connect(ui->penWidthHorizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(penWidthChanged(int)));
    connect(ui->changeColorPushButton, SIGNAL(clicked()), this, SLOT(changeColorButtonClicked()));

    updateColorWidget(_currentColor);
}

void MainWindow::updateColorWidget(QColor color)
{
    QPalette palette;
    palette.setColor(QPalette::Background, color);
    ui->colorwidget->setPalette(palette);
    ui->colorwidget->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::levelChanged(int level)
{
    ui->fractalFrame->levelChanged(level);
}

void MainWindow::segmentPixelSizeChanged(int segmentPixelSize)
{
    ui->fractalFrame->segmentPixelSizeChanged(segmentPixelSize);
}

void MainWindow::penWidthChanged(int penWidth)
{
    ui->fractalFrame->penWidthChanged(penWidth);
}

void MainWindow::changeColorButtonClicked()
{
    QColor color = QColorDialog::getColor(_currentColor, this);
    if (!color.isValid())
        return;
    _currentColor = color;
    updateColorWidget(_currentColor);
    ui->fractalFrame->fractalColorChanged(_currentColor);
}
