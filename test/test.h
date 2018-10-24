#pragma once

#include <QtWidgets/QWidget>
#include "ui_test.h"
#include <QGraphicsScene>//���ڹ�������Զ���� 2D ͼ��Ԫ�أ�����֮���н���
#include <QWidget>
#include <QGraphicsView>//���ڹ�������Զ���� 2D ͼ��Ԫ�أ�����֮���н���
#include <QTimer>
#include <QPoint>//��ͼ��
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
	static const int GRID_SIZE = 80; // ÿ�����ӵı߳�
public:
	explicit test(QWidget *parent = nullptr);
	vector<int> z_position;
	vector<vector<double>>  graph_cost;
	QGraphicsScene scene_;//���������������������ͼ�εĿռ䣬�൱���������磻
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
