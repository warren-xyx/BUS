#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "New.h"
using namespace std;

int main() {
	cout << "公交线路查询" << endl;
	cout << "从线路记录中获取站点信息" << endl;

	// 初始化站点存储空间
	Elem data1[41] = {};
	Elem data2[52] = {};
	int n1 = 41;
	int n2 = 52;
	// 从 Load1.txt 文件中读取第一条线路的信息
	OutFile("Load-one.txt", data1, n1);
	OutFile("Load-18.txt", data2, n2);
	// 根据 data 创建线路表 L1
	LoadNode* L1;
	LoadNode* L2;
	LoadNode* L11;
	LoadNode* L22;
	CreateLoad1(L1, data1, n1);
	CreateLoad1(L2, data2, n2);
	CreateLoad2(L11, data1, n1);
	CreateLoad2(L22, data2, n2);
	cout << "成功创建线路 L1" << endl;
	DispLoad(L1);
	DispLoad(L11);
	cout << "成功创建线路 L2" << endl;
	DispLoad(L2);
	DispLoad(L22);
	
	while (1)
	{
		cout << "查询路线：y\n" << "退出：n" << endl;
		cout << "是否继续查询：";
		char t;
		cin >> t;
		if (t == 'n')
			break;

		// 通过用户的上车下车站点，给出最优线路建议
		string begin;
		string end;
		cout << "输入你的上车站点" << endl;
		cin >> begin;
		cout << "输入你的下车站点" << endl;
		cin >> end;
		Suggestion2(begin, end, L1, L11, L2, L22);
	}
	cout << "祝你乘车愉快！" << endl;
	cout << L1 << endl;
	return 0;
}