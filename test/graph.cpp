#include "graph.h"

class UF
{
private:
	vector<int> id;
public:
	UF(int n)
	{
		for (int i = 0; i < n; i++)
		{
			id.push_back(i);
		}
	}
	bool connect(int p, int q)
	{
		return id[p] == id[q];
	}

	void union_(int p, int q)
	{
		int pid = id[p];
		int qid = id[q];
		if (connect(p, q))
		{
			return;
		}
		else
		{
			for (int i = 0; i < id.size(); i++)
			{
				if (id[i] == pid)
				{
					id[i] = qid;
				}
			}
		}
	}
};
graph::graph()
{	
}
graph::~graph()
{
}
bool  CmpByValue(const pair<pair<int, int>, double> &s1, const pair<pair<int, int>, double> &s2)
{
	if (s1.second >= s2.second)
		return 0;
	else
		return 1;
}

pair<vector<vector<double>>,vector<string>>graph::get_graph()
{
	fstream graph_file("最小生成树.txt");
	string line;
	getline(graph_file, line);
	cout << line << endl;
	//从文件中读出矩阵的行。
	int q = line.find("是") + 2;//汉字是2字节字符。
	row = stod(line.substr(q, 2));
	cost.resize(row);
	for(int k = 0; k < row; ++k)
	{
		cost[k].resize(row);//每行为c列
	}
	//从文件得到矩阵的值和其含义。
	getline(graph_file, line);//读取第二行，
	int w = 0;
	while (getline(graph_file, line))
	{
		string cost_string;
		int q = line.find("	");
		position.push_back(line.substr(0, q));
		for (int i = 0; i < row; i++)
		{
			int q1 = line.find("	", q + 1);
			cost_string = line.substr(q + 1, q1 - (q + 1));
			cost[w][i] = stod(cost_string);
			q = q1;
		}
		w++;
	}
	return make_pair(cost,position);
}
void graph::Kruskal()
{
	vector<pair<pair<int, int>, double>> all_cost;
	deque<pair<int, int>> min_cost;
	double min_all_cost = 0.0;
	for (int w = 0; w < cost.size(); w++)
	{
		for (int w0 = 0; w0 < w; w0++)
		{
			all_cost.push_back(make_pair(make_pair(w, w0), cost[w][w0]));
		}
	}
	sort(all_cost.begin(), all_cost.end(), CmpByValue);
	for (auto w = all_cost.begin(); w != all_cost.end(); w++)
	{
		min_cost.push_back(w->first);
	}
	//开始正式的代码部分。
	UF union_find(row);
	while (kmin_cost_tree.size() < row - 1 && min_cost.size() != 0)
	{

		pair<int, int> q = min_cost.front();
		min_cost.pop_front();
		if (union_find.connect(q.first, q.second))
			continue;
		union_find.union_(q.first, q.second);
		kmin_cost_tree.push_back(q);
		min_all_cost += cost[q.first][q.second];
	}
	ofstream tree_file("Kruskal最小生成树");
	for (auto w = kmin_cost_tree.begin(); w != kmin_cost_tree.end(); w++)
	{
		 tree_file<< w->first << "(" << position[w->first] << ")->" << w->second << "(" << position[w->second] << "):" << cost[w->first][w->second] << endl;
	}
	tree_file << "最小的权重和为:" << min_all_cost << endl;
}
void graph::Prim()
{
	vector<int> near(row, 0);//下标为最小生成树外边的点，对应的值为最小生成树内的点（并保证其权值为外边的点到树内的点的最小值。）
	double mincost = 0;
	//先寻找一个权值最小的边
	int min_cost = 10000, j, k;
	for (int i = 0; i < cost.size(); i++)
	{
		auto min = min_element(cost[i].begin(), cost[i].end());
		if (*min < min_cost)
		{
			min_cost = *min;
			j = i;
			k = distance(begin(cost[i]), min);
		}
	}
	mincost += min_cost;
	pmin_cost_tree.push_back(make_pair(j, k));
	//更新near
	for (int i = 0; i < row; i++)
	{
		if (cost[i][j] > cost[i][k])
		{
			near[i] = k;
		}
		else
		{
			near[i] = j;
		}
	}
	near[j] = near[k] = -1;
	//求其他的最小生成树.
	for (int i = 2; i < row; i++)
	{
		int x, min_cost = 10000;
		//求出最小的权值。
		for (int w = 0; w < near.size(); w++)
		{
			if (near[w] != -1)
			{
				if (cost[w][near[w]] < min_cost)
				{
					x = w;
					min_cost = cost[w][near[w]];
				}
			}
		}
		pmin_cost_tree.push_back(make_pair(x, near[x]));
		near[x] = -1;
		mincost += min_cost;
		//修改near
		for (int k = 0; k < near.size(); k++)
		{
			if (near[k] != -1)
			{
				if (cost[k][near[k]] > cost[k][x])
				{
					near[k] = x;
				}
			}
		}
	}
	ofstream tree_file("prim最小生成树");
	for (auto w = pmin_cost_tree.begin(); w != pmin_cost_tree.end(); w++)
	{
		tree_file << w->first << "(" << position[w->first] << ")->" << w->second << "(" << position[w->second] << "):" << cost[w->first][w->second] << endl;
	}
	tree_file << "最小的权重和为:" << mincost << endl;
}
pair<int, int> graph::get_kpath()
{
	if (kmin_cost_tree.size() != 0)
	{
		pair<int, int> t = kmin_cost_tree.front();
		kmin_cost_tree.erase(kmin_cost_tree.begin());
		return t;
	}
	else
	{
		return make_pair(-1, -1);
	}
}
pair<int, int> graph::get_ppath()
{
	if (pmin_cost_tree.size() != 0)
	{
		pair<int, int> t = pmin_cost_tree.front();
		pmin_cost_tree.erase(pmin_cost_tree.begin());
		return t;
	}
	else
	{
		return make_pair(-1, -1);
	}
}
