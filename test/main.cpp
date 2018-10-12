#include "test.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	test w;
	w.show();
	/*
	string d = "地铁站人 ";
	QGraphicsTextItem pItem;
	pItem.setPlainText(QString::fromLocal8Bit(d.c_str()));
	QGraphicsTextItem *pItem1 = new QGraphicsTextItem();
	pItem1->setPlainText(QString::fromLocal8Bit("21世纪路"));

	// 将 item 添加至场景中
	QGraphicsScene *pScene = new QGraphicsScene();
	pItem.setPos(QPointF(qreal(0.0), qreal(200.0)));      //设置字体的位置
	pItem1->setPos(QPointF(qreal(-50.0), qreal(20.0)));
	QGraphicsLineItem *p = new QGraphicsLineItem();
	p->setLine(0, 200, -50, 20);
	pScene->addItem(&pItem);
	pScene->addItem(pItem1);
	pScene->addItem(p);
	// 为视图设置场景
	QGraphicsView *pView = new QGraphicsView();
	pView->resize(500, 600);
	pView->setScene(pScene);
	pView->show();
	*/
	return a.exec();
}
