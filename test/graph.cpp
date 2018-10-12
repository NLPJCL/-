#include "graph.h"



graph::graph()
{
}


graph::~graph()
{
}
pair<vector<vector<double>>,vector<string>>graph::get_graph()
{
	fstream graph_file("��С������.txt");
	string line;
	getline(graph_file, line);
	cout << line << endl;
	//���ļ��ж���������С�
	int q = line.find("��") + 2;//������2�ֽ��ַ���
	int row = stod(line.substr(q, 2));
	vector<vector<double>> cost(row, vector<double>(row, 0));//10000�������
	vector<string> position;
	//���ļ��õ������ֵ���京�塣
	getline(graph_file, line);//��ȡ�ڶ��У�
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
	//��ȡ����Ԫ���ԡ�
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
