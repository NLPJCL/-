#pragma once

#include <QtWidgets/QWidget>
#include "ui_test.h"
#include <QGraphicsScene>//用于管理大量自定义的 2D 图形元素，并与之进行交互
#include <QWidget>
#include <QGraphicsView>//用于管理大量自定义的 2D 图形元素，并与之进行交互
#include <QTimer>
#include <QPoint>//绘图库
#include <QGraphicsItemGroup>
#include<string>
#include"graph.h";
#include<vector>
#include<QString>
#include<set>
#include"table.h"
namespace Ui {
	class test;
}
class test : public QGraphicsView
{
	Q_OBJECT
	static const int WIDTH = 13;
	static const int HEIGHT =13;
	static const int GRID_SIZE = 80; // 每个格子的边长
public:
	explicit test(QWidget *parent = nullptr);
	vector<int> z_position;
	vector<vector<double>>  graph_cost;
	QGraphicsScene scene_;//场景，即是允许我们添加图形的空间，相当于整个世界；
	QTimer* timer_;
	graph graph_;
	QPoint points_[WIDTH][HEIGHT];
	void paint_graph();
private:
	Ui::testClass *ui;
	QGraphicsTextItem position[WIDTH];
	QGraphicsLineItem line[WIDTH*HEIGHT];
	QGraphicsTextItem cost[WIDTH*HEIGHT];
private slots:
	void timeout();
	void prim();
	void Kruskal();
};
