#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class graph
{
public:
	graph();
	pair<vector<vector<double>>, vector<string>> get_graph();
	~graph();
private:
	int x0;
	int y0;
	int level;
	int current_x;
	int current_y;
	int grid[10][9];//grid¶þÎ¬Êý×é¡£
	vector<vector<int>> graph_;
};

