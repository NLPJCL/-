#include "graph.h"



graph::graph()
{
}


graph::~graph()
{
}
pair<vector<vector<double>>,vector<string>>graph::get_graph()
{
	fstream graph_file("最小生成树.txt");
	string line;
	getline(graph_file, line);
	cout << line << endl;
	//从文件中读出矩阵的行。
	int q = line.find("是") + 2;//汉字是2字节字符。
	int row = stod(line.substr(q, 2));
	vector<vector<double>> cost(row, vector<double>(row, 0));//10000是正无穷。
	vector<string> position;
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
	cout << "	";
	for (auto w = position.begin(); w != position.end(); w++)
	{
		cout << *w << " ";
	}
	cout << endl;
	//读取矩阵单元测试。
	for (int w = 0; w < cost.size(); w++)
	{
		cout << position[w] << " ";
		for (int w0 = 0; w0 < cost[w].size(); w0++)
		{
			cout << cost[w][w0] << "	";
		}
		cout << endl;
	}
	return make_pair(cost,position);
}
