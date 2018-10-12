#include "test.h"
#include <QDebug>
test::test(QWidget *parent) :
	QGraphicsView(parent),
	ui(new Ui::testClass)
{
	ui->setupUi(this);//��ui��view����������
	timer_ = new QTimer(this);//����һ����ʱ������
	scene_.setParent(this);
	this->resize(13* GRID_SIZE + 20, 13 * GRID_SIZE + 20);//������Ļ�ĳ���
	this->setScene(&scene_);//��view��scene����������
	connect(timer_, SIGNAL(timeout()), this, SLOT(timeout()));//����ʱ��������ۻ��ƹ���������
	//����ͼ
	//this->setWindowTitle("123456");
	paint_graph();
	/*
	for (QGraphicsTextItem& l : position)
	{
		scene_.addItem(&l);//����grid_meridian�ĳ�Ա��scene�С�
	}
	*/

	for (QGraphicsLineItem& l : line)
	{
		scene_.addItem(&l);
	}
	//this->setAlignment(Qt::AlignCenter);
	timer_->start(100);
}
void test::timeout()
{
	if (0)//�����Ϊ�գ����������ʱ����
	{
		timer_->stop();
		return;
	}
	//����ͼ��
	/*
	QGraphicsLineItem* l = new QGraphicsLineItem(0, 0, 10, 10);//��ʼ����յ�����ֱ��� (x1, y1) �� (x2, y2);
	QPen pen;
	pen.setColor(Qt::red);
	pen.setWidth(3);
	l->setPen(pen);
	scene_.addItem(l);
	update();
	*/
}

void test::paint_graph()
{
	pair<vector<vector<double>>, vector<string>> w = graph_.get_graph();
	vector<vector<double>>  graph = w.first;
	vector<string> position_name= w.second;

	//��13*13���㶼�Һ��ˡ�
	for (int y = 0; y < graph.size(); ++y)
	{
		for (int x = 0; x < graph.size(); ++x)
		{
			int xvalue = 10 + x * GRID_SIZE;
			int yvalue = 10 + y * GRID_SIZE;
			points_[y][x] = QPoint{ xvalue, yvalue };
		}
	}
	//д���֡�
	for (int i = 0; i < position_name.size(); i++)
	{
		position[i].setPlainText(QString::fromLocal8Bit(position_name[i].c_str()));
	}
	//��λ�á�

	for (int i = 0; i < graph.size(); i++)
	{
		for (int j = 0; j < graph.size(); j++)
		{

		}
	}


	position[0].setPos(points_[0][0].x(), points_[0][0].y());
	position[1].setPos(points_[0][1].x(), points_[0][1].y());
	position[2].setPos(points_[1][0].x(), points_[1][0].y());
	position[3].setPos(points_[1][1].x(), points_[1][1].y());
	
	//��ͼ����ɡ�
	int q = 0;
	for (int i = 0; i < graph.size(); ++i)
	{
		for (int j = 0; j < graph[i].size(); ++j)
		{
			if (graph[i][j] != 10000)
			{
				if (i < 2)
				{
					line[q].setLine(points_[0][i].x(), points_[0][i].y(), points_[0][j].x(), points_[0][j].y());
				}
				else
				{
					line[q].setLine(points_[1][i].x(), points_[1][i].y(), points_[1][j].x(), points_[1][j].y());
				}
				q++;
			}
		}
	}
}
