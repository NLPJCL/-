#include <iostream>
#include <string>
#include<math.h>
#include<fstream>
#include<vector>

using namespace std;
class table
{
public:
	table();
	int single, size1;
	int coordinate[100][3];//第一个点为限制点
	void Initialization(); 
	vector<vector<double>> get_graph();
	void coo();
	void correct();
private:
	int basic[100], is[100], ns[100];
	int length;
	vector<vector<double>> cost;
	//int want[][];
	int z, n;
	int s1, s2, s3, s4;//s1，s3为横坐标
	int absolute(int a, int b);
	int distance(int a, int b);
	int distance2(int a, int b);
	int straight(int a, int b, int c);
	void circle(int a, int b, int c);
	void scan(int a);
	void is1();
	void is1(int a[]);
	void ns1();
	//引入待使用数组
};