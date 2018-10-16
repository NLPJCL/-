#include "test.h"
#include <QDebug>
bool place(int k, vector<int> X)
{

	int i = 0;
	while (i < k)
	{
		if (X[i] == X[k] || abs(X[i] - X[k]) == abs(i - k))
		{
			return 0;
		}
		i++;
	}
	return 1;
}
//���ݽṹ��X[k]�Ǵ洢��������飬�±�����У����Ӧ��ֵ�����С�
set<vector<int>> Nqueens(int n)
{
	set<vector<int>> Z;
	int k;
	vector<int> X(n, -1);
	X[0] = -1; k = 0;
	while (k >= 0)
	{
		X[k]++;
		//ѡ���С�
		while (X[k] <= n - 1 && !place(k, X))
		{
			X[k]++;
		}
		if (X[k] <= n - 1)
		{
			if (k == n - 1)
			{
				Z.insert(X);
				if (Z.size()==8)
				{
					return Z;
				}
				vector<int> X(n, -1);
			}
			else
			{
				k = k + 1;
				X[k] = -1;
			}
		}
		else
		{
			k = k - 1;
		}
	}
	return Z;
}
test::test(QWidget *parent) :
	QGraphicsView(parent),
	ui(new Ui::testClass),graph_()
{
	ui->setupUi(this);//��ui��view����������
	timer_ = new QTimer(this);//����һ����ʱ������
	scene_.setParent(this);
	this->resize(13* GRID_SIZE + 20, 13 * GRID_SIZE + 20);//������Ļ�ĳ���
	this->setScene(&scene_);//��view��scene����������
	connect(timer_, SIGNAL(timeout()), this, SLOT(timeout()));//����ʱ��������ۻ��ƹ���������
	connect(ui->P, SIGNAL(clicked(bool)), this, SLOT(prim()));
	connect(ui->K, SIGNAL(clicked(bool)), this, SLOT(Kruskal()));
	//����ͼ
	//this->setWindowTitle(QString::fromLocal8Bit("��У����С������"));
	paint_graph();
	for (QGraphicsTextItem& l : position)
	{
		scene_.addItem(&l);//����grid_meridian�ĳ�Ա��scene�С�
	}
	for (QGraphicsLineItem& l : line)
	{
		scene_.addItem(&l);
	}
	for (QGraphicsTextItem& l : cost)
	{
		scene_.addItem(&l);
	}
}
void test::timeout()
{
	pair<int, int> path;
	if (graph_.kmin_cost_tree.size() != 0)
	{
		path = graph_.get_kpath();

	}
	else
	{
	path = graph_.get_ppath();
	}

	if (path.first==-1)//�����Ϊ�գ����������ʱ����
	{
		timer_->stop();
		for (QGraphicsLineItem &l : line)
		{
			scene_.removeItem(&l);
		}
		for (QGraphicsTextItem &l : cost)
		{
			scene_.removeItem(&l);
		}
		return;
	}
	else
	{
		QGraphicsLineItem *line = new QGraphicsLineItem();
		QGraphicsTextItem *cost = new QGraphicsTextItem();
		line->setLine(points_[path.first][z_position[path.first]].x(), points_[path.first][z_position[path.first]].y(),
		points_[path.second][z_position[path.second]].x(), points_[path.second][z_position[path.second]].y());
		QPen pen;
		pen.setColor(Qt::red);
		pen.setWidth(3);
		line->setPen(pen);
		cost->setPlainText(QString::number(graph_cost[path.first][path.second]));
		cost->setPos((points_[path.first][z_position[path.first]].x() + points_[path.second][z_position[path.second]].x()) / 2,
			(points_[path.first][z_position[path.first]].y() + points_[path.second][z_position[path.second]].y()) / 2);
		cost->setDefaultTextColor("red");
		scene_.addItem(line);
		scene_.addItem(cost);
	}
	update();
}

void test::paint_graph()
{
	pair<vector<vector<double>>, vector<string>> w = graph_.get_graph();
	graph_cost = w.first;
	vector<string> position_name= w.second;

	//��13*13���㶼�Һ��ˡ�
	for (int y = 0; y <  graph_cost.size(); ++y)
	{
		for (int x = 0; x <  graph_cost.size(); ++x)
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
	set<vector<int>> q0 = Nqueens(13);
	auto z = q0.begin();
	for (int i = 0; i < 7; i++)
	{
		z++;
	}
	z_position = *z;
	for (int i=0;i<z->size();i++)
	{
		position[i].setPos(points_[i][(*z)[i]].x(), points_[i][(*z)[i]].y());

	}
	int q = 0;
	for (int i = 0; i <  graph_cost.size(); ++i)
	{
		for (int j = 0; j <  graph_cost[i].size(); ++j)
		{
			if (graph_cost[i][j] != 10000)
			{
					line[q].setLine(points_[i][(*z)[i]].x(), points_[i][(*z)[i]].y(), points_[j][(*z)[j]].x(), points_[j][(*z)[j]].y());
					cost[q].setPlainText(QString::number(graph_cost[i][j]));
					cost[q].setPos((points_[i][(*z)[i]].x()+ points_[j][(*z)[j]].x() )/2, (points_[i][(*z)[i]].y()+ points_[j][(*z)[j]].y())/2);
					q++;
			}
		}
	}
}

void test::prim()
{
	graph_.Prim();
	timer_->start(500);

}

void test::Kruskal()
{
	graph_.Kruskal();
	timer_->start(1000);
}
