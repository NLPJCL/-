#pragma once

#include <QtWidgets/QWidget>
#include "ui_test.h"
#include <QGraphicsScene>//用于管理大量自定义的 2D 图形元素，并与之进行交互
#include <QWidget>
#include <QGraphicsView>//用于管理大量自定义的 2D 图形元素，并与之进行交互
#include <QTimer>
#include <random>
#include <QPoint>//绘图库
#include <QGraphicsItemGroup>
#include<string>
#include"graph.h";
#include<vector>
#include<QString>
namespace Ui {
	class test;
}
class test : public QGraphicsView
{
	Q_OBJECT
	static const int WIDTH = 13;
	static const int HEIGHT =13;
	static const int GRID_SIZE = 500; // 每个格子的边长
public:
	explicit test(QWidget *parent = nullptr);
	QGraphicsScene scene_;//场景，即是允许我们添加图形的空间，相当于整个世界；
	QTimer* timer_;
	graph graph_;
	//QGraphicsLineItem grid_meridian_[10];//作为图形元件，以便添加到场景中去，Qt 内置了很多图形
	//QGraphicsLineItem grid_latitude_[16];//网格的维度
	QPoint points_[HEIGHT][WIDTH];
	void paint_graph();
	//vector<QGraphicsLineItem> line;
private:
	Ui::testClass *ui;
	QGraphicsTextItem position[WIDTH];
	QGraphicsLineItem line[100];
	//vector<QGraphicsLineItem> line;
private slots:
	void timeout();
};
