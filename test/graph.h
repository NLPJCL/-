#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<set>
#include <algorithm>  
#include<deque>
using namespace std;
class graph
{
	friend class test;
public:
	graph();
	pair<vector<vector<double>>, vector<string>> get_graph();
	void Kruskal();
	pair<int,int> get_kpath();
	pair<int, int>  get_ppath();
	void Prim();
	~graph();
private:
	int row;
	vector<vector<double>> cost;
	vector<string> position;
	vector<pair<int, int>> kmin_cost_tree;//Kruskal最小生成树的边，
	vector<pair<int, int>> pmin_cost_tree;//prim最小生成树的边。
};

