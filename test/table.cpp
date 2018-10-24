#include"table.h"

vector<vector<double>> table::get_graph()
{
	int row;
	vector<string> position;
	fstream graph_file("最小生成树.txt");
	string line;
	getline(graph_file, line);
	//	cout << line << endl;
	//从文件中读出矩阵的行。
	int q = line.find("是") + 2;//汉字是2字节字符。
	row = stod(line.substr(q, 2));
	cost.resize(row);
	for (int k = 0; k < row; ++k)
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
			if (stod(cost_string) != 10000)
			{
				cost[w][i] = int(stod(cost_string) / double(10));
			}
			else
			{
				cost[w][i] = stod(cost_string);
			}
			q = q1;
		}
		w++;
	}

	//	cout << "	";
	//	for (auto w = position.begin(); w != position.end(); w++)
	//	{
	//		cout << *w << " ";
	//	}
	//	cout << endl;
	//读取矩阵单元测试。
	//	for (int w = 0; w < cost.size(); w++)
	//	{
	//		cout << position[w] << " ";
	//		for (int w0 = 0; w0 < cost[w].size(); w0++)
	//		{
	//			cout << cost[w][w0] << "	";
	//		}
	//		cout << endl;
	//	}

	return cost;
}
void table::Initialization() {
	n = 1, s1 = s2 = s3 = s4 = 0;
	length = cost.size();
	for (int i = 0; i<100; i++) {
		for (int j = 0; j<3; j++) {
			coordinate[i][j] = 0;
		}
	}
	for (int i = 0; i<100; i++) {
		basic[i] = 0;
	}
}
int table::absolute(int a, int b) {
	z = 0; int x = 0;
	x = a - b;
	if (x<0)
		z = 0 - x;
	else
		z = x;
	return z;
}
int table::distance(int a, int b) {
	//a[5][0],a[7][0]
	z = 0;
	if (coordinate[a][2] == 0 || coordinate[b][2] == 0) {
		z = -1;
	}
	else {
		z = sqrt(pow(absolute(coordinate[a][0], coordinate[b][0]), 2) + pow(absolute(coordinate[a][1], coordinate[b][1]), 2));
	}
	return z;

}
int table::distance2(int a, int b) {
	z = cost[a - 1][b - 1];
	return z;
}
//判断是否为一条线
int table::straight(int a, int b, int c)
{
	int x, y, z, max, mid, min;
	x = distance(a, b);
	y = distance(a, c);
	z = distance(b, c);
	max = x;
	if (y>max)
		max = y;
	if (z>max)
		max = z;
	min = x;
	if (y<min)
		min = y;
	if (z<min)
		min = z;
	mid = x;
	if (mid == max || mid == min)
		mid = y;
	if (mid == max || mid == min)
		mid = z;
	if (mid + min - 1<max&&max<mid + min + 1) {
		return 1;
	}
	else {
		return 0;
	}

}
//圆求解
void table::circle(int a, int b, int c)
{
	int a1, a2, b1, b2, c1, c2, z, e;
	s1 = s2 = s3 = s4 = 0; single = -1;
	a1 = coordinate[a][0];
	b1 = coordinate[a][1];
	a2 = coordinate[b][0];
	b2 = coordinate[b][1];
	c1 = pow(distance2(a, c), 2);
	c2 = pow(distance2(b, c), 2);
	if (2 * a1 - 2 * a2 != 0) {
		z = (2 * b2 - 2 * b1) / (2 * a1 - 2 * a2);
		e = ((c2 - c1 + pow(a1, 2) - pow(a2, 2) + pow(b1, 2) - pow(b2, 2)) / (2 * a1 - 2 * a2) - a1);
		if ((pow((2 * e*z - 2 * b1), 2) - 4 * (pow(z, 2) + 1)*(pow(e, 2) + pow(b1, 2) - c1))>0) {
			s2 = (2 * (b1 - z * e) + sqrt((pow((2 * e*z - 2 * b1), 2) - 4 * (pow(z, 2) + 1)*(pow(e, 2) + pow(b1, 2) - c1)))) / (2 * (pow(z, 2) + 1));
			s1 = z * s2 + e + a1;
			s4 = (2 * (b1 - z * e) - sqrt((pow((2 * e*z - 2 * b1), 2) - 4 * (pow(z, 2) + 1)*(pow(e, 2) + pow(b1, 2) - c1)))) / (2 * (pow(z, 2) + 1));
			s3 = z * s4 + e + a1;
			single = 1;
		}
		else {
			if ((pow((2 * e*z - 2 * b1), 2) - 4 * (pow(z, 2) + 1)*(pow(e, 2) + pow(b1, 2) - c1)) == 0) {
				s2 = (2 * (b1 - z * e) + sqrt((pow((2 * e*z - 2 * b1), 2) - 4 * (pow(z, 2) + 1)*(pow(e, 2) + pow(b1, 2) - c1)))) / (2 * (pow(z, 2) + 1));
				s1 = z * s2 + e + a1;
				single = 0;
			}
			else {
				cout << "该点无法求解1" << endl;
			}
		}
	}
	if ((2 * b1 - 2 * b2 != 0) && (2 * a1 - 2 * a2 == 0)) {
		z = (2 * a2 - 2 * a1) / (2 * b1 - 2 * b2);
		e = ((c2 - c1 + pow(b1, 2) - pow(b2, 2) + pow(a1, 2) - pow(a2, 2)) / (2 * b1 - 2 * b2) - b1);
		if ((pow((2 * e*z - 2 * a1), 2) - 4 * (pow(z, 2) + 1)*(pow(e, 2) + pow(a1, 2) - c1))>0) {
			s1 = (2 * (a1 - z * e) + sqrt((pow((2 * e*z - 2 * a1), 2) - 4 * (pow(z, 2) + 1)*(pow(e, 2) + pow(a1, 2) - c1)))) / (2 * (pow(z, 2) + 1));
			s2 = z * s1 + e + a1;
			s3 = (2 * (a1 - z * e) - sqrt((pow((2 * e*z - 2 * a1), 2) - 4 * (pow(z, 2) + 1)*(pow(e, 2) + pow(a1, 2) - c1)))) / (2 * (pow(z, 2) + 1));
			s4 = z * s3 + e + a1;
			single = 1;
		}
		else {
			if ((pow((2 * e*z - 2 * a1), 2) - 4 * (pow(z, 2) + 1)*(pow(e, 2) + pow(a1, 2) - c1)) == 0) {
				s1 = (2 * (a1 - z * e) + sqrt((pow((2 * e*z - 2 * a1), 2) - 4 * (pow(z, 2) + 1)*(pow(e, 2) + pow(a1, 2) - c1)))) / (2 * (pow(z, 2) + 1));
				s2 = z * s1 + e + a1;
				single = 0;
			}
			else {
				cout << "该点无法求解2" << endl;
			}
		}
	}
}
//扫描函数
void table::scan(int a) {
	if (a != 0 && (a <= length)) {
		for (int i = 0; i<100; i++) {
			basic[i] = 0;
		}
		int x = 0;
		for (int i = 0; i<cost[a - 1].size(); i++) {
			if (cost[a - 1][i] != 10000) {
				basic[x] = i + 1;
				x++;
			}
		}
	}
}


//坐标确定函数
void table::is1() {
	for (int i = 0; i<100; i++) {
		is[i] = 0;
	}int j = 0;
	for (int i = 1; i <= length; i++) {
		if (coordinate[i][2] == 1) {
			is[j] = i; j++;
		}
	}
}
void table::is1(int a[]) {
	for (int i = 0; i<100; i++) {
		is[i] = 0;
	}int j = 0;
	for (int i = 0; i<100; i++) {
		if (coordinate[a[i]][2] != 0) {
			is[j] = i + 1; j++;
		}
		if (coordinate[a[i]][2] == 0)
			break;
	}
}
void table::ns1() {
	for (int i = 0; i<100; i++) {
		ns[i] = 0;
	}int j = 0;
	for (int i = 1; i <= length; i++) {
		if (coordinate[i][2] == 0) {
			ns[j] = i; j++;
		}
	}
}
void table::coo() {
	//cout<<"n="<<n<<endl;
	ns1();
	if (n == 1 || ns[0] != 0) {
		if (n == 1) {
			coordinate[1][0] = 1;
			coordinate[1][1] = 1;
			coordinate[1][2] = 1;
			n++;
		}
		else {
			if (n == 2) {
				scan(1);
				int two;
				two = basic[0];
				coordinate[two][0] = distance2(1, two) + 1;
				coordinate[two][1] = 1;
				coordinate[two][2] = 1;
				n++;
			}
			else {
				if (n == 3) {
					is1(); ns1();
					int th1, th2, th3; int i = 0;
					th1 = is[0]; th2 = is[1]; th3 = ns[i];
					while (ns[i]) {
						if (straight(th1, th2, th3) != 1 && (distance2(th1, th3) != 10000) && (distance2(th2, th3) != 10000)) {
							circle(th1, th2, th3); break;
						}
						i++; th3 = ns[i];
					}
					if (single == 0) {
						coordinate[th3][0] = s1;
						coordinate[th3][1] = s2;
						coordinate[th3][2] = 1;
					}if (single == 1) {
						int line;
						cout << "选择一个坐标作为第三点" << endl;
						cout << "第一个解" << s1 << "," << s2 << "第二个解" << s3 << "," << s4 << endl;
						line = 1;
						if (line == 1) {
							coordinate[th3][0] = s1;
							coordinate[th3][1] = s2;
							coordinate[th3][2] = 1;
							n++;
						}
						if (line == 0) {
							coordinate[th3][0] = s3;
							coordinate[th3][1] = s4;
							coordinate[th3][2] = 1;
							n++;
						}
					}
				}
				else {
					if (n>3) {
						coordinate[0][0] = 0;
						coordinate[0][1] = 0;
						coordinate[0][2] = 0;
						is1(); ns1();
						int th1, th2, th3, th4, tr1, tr2, tr3, tr4;
						int i = 0;
						int p1, p2, p3; p1 = 0; p2 = 1; p3 = 2;
						int j = 0;
						//			for(int zi=0;zi<100;zi++){
						//				cout<<ns[zi]<<",";
						//				}
						while (ns[i]) {
							th3 = ns[i];
							scan(th3);
							//			for(int i=0;i<100;i++){
							//						cout<<basic[i]<<",";
							//						}
							is1(basic);
							//			for(int i=0;i<100;i++){
							//			cout<<is[i]<<",";
							//			}
							//cout<<ns[i]<<endl;
							while (is[j]) {
								j++;
							}j = j - 1;

							if (is[p1])
								th1 = is[p1];
							if (is[p2])
								th2 = is[p2];
							if (is[p3])
								th4 = is[p3];
							for (; p1 <= j; p1++) {
								for (; p2 <= j; p2++) {
									for (; p3 <= j; p3++) {
										if (is[p1])
											th1 = is[p1];
										if (is[p2])
											th2 = is[p2];
										if (is[p3])
											th4 = is[p3];
										if (straight(th1, th2, th4) == 0) {
											tr1 = th1; tr2 = th2; tr3 = th3; tr4 = th4;
											circle(th1, th2, th3);
										}
										if (single != -1)
											break;
									}p3 = p2 + 1;
									if (single != -1)
										break;
								}p2 = p1 + 1;
								if (single != -1)
									break;
							}
							i++; if (single != -1)
								break;

						}
						if (single == 0) {
							coordinate[tr3][0] = s1;
							coordinate[tr3][1] = s2;
							coordinate[tr3][2] = 1;

						}if (single == 1) {
							int line1, line2;
							coordinate[0][0] = s1;
							coordinate[0][1] = s2;
							coordinate[0][2] = 1;
							line1 = absolute(distance(tr4, 0), distance2(tr3, tr4));
							coordinate[0][0] = s3;
							coordinate[0][1] = s4;
							coordinate[0][2] = 1;
							line2 = absolute(distance(tr4, 0), distance2(tr3, tr4));
							if (line1 <= line2) {
								coordinate[tr3][0] = s1;
								coordinate[tr3][1] = s2;
								coordinate[tr3][2] = 1;
								n++;
							}
							if (line2<line1) {
								coordinate[tr3][0] = s3;
								coordinate[tr3][1] = s4;
								coordinate[tr3][2] = 1;
								n++;
							}
						}
					}


				}
			}
		}coo();
	}

}
void table::correct() {
	int max = 0; int min = 0; int i = 0;
	for (i = 1; i<100; i++) {
		for (int j = 0; j<3; j++) {
			if (max<coordinate[i][j])
				max = coordinate[i][j];
			if (min>coordinate[i][j])
				min = coordinate[i][j];
		}
	}size1 = 1.2*(max - min);
	is1(); i = 0;
	while (is[i]) {
		for (int j = 0; j<3; j++)
			coordinate[is[i]][j] -= min;
		i++;
	}

}
table::table()
{

}