#pragma once

#include <QtWidgets/QWidget>
#include "ui_test.h"
#include <QGraphicsScene>//���ڹ�������Զ���� 2D ͼ��Ԫ�أ�����֮���н���
#include <QWidget>
#include <QGraphicsView>//���ڹ�������Զ���� 2D ͼ��Ԫ�أ�����֮���н���
#include <QTimer>
#include <random>
#include <QPoint>//��ͼ��
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
	static const int GRID_SIZE = 500; // ÿ�����ӵı߳�
public:
	explicit test(QWidget *parent = nullptr);
	QGraphicsScene scene_;//���������������������ͼ�εĿռ䣬�൱���������磻
	QTimer* timer_;
	graph graph_;
	//QGraphicsLineItem grid_meridian_[10];//��Ϊͼ��Ԫ�����Ա���ӵ�������ȥ��Qt �����˺ܶ�ͼ��
	//QGraphicsLineItem grid_latitude_[16];//�����ά��
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
