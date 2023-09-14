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
		int in = 0;
		cout << "增加站点操作：" << 1 << endl;
		cout << "删除站点操作：" << 2 << endl;
		cout << "修改站点操作：" << 3 << endl;
		cout << "查询站点操作：" << 4 << endl;
		cout << "查询路线操作：" << 5 << endl;
		cout << "你的输入：" ;
		cin >> in;
		if (in == 1) //增加
		{
			int t = 0;
			cout << "给 L1 增加站点：" << 1 << endl;
			cout << "给 L2 增加站点" << 2 << endl;
			cin >> t;
			if (t == 1)
			{
				int i;
				Elem data = {};
				cout << "插入站的名称：" ;
				cin >> data.name;
				cout << "插入站与前一站的距离：";
				cin >> data.length;
				cout << "插入站是否为换乘站：";
				cin >> data.tag;
				cout << "插入到 L1 的位置：" ;
				cin >> i;
				data.i = i;
				InsertElem(L1, i, data);
				cout << "目前 L1 路线图：";
				DispLoad(L1);
			}
			else if (t == 2)
			{
				int i;
				Elem data = {};
				cout << "插入站的名称：";
				cin >> data.name;
				cout << "插入站与前一站的距离：";
				cin >> data.length;
				cout << "插入站是否为换乘站：";
				cin >> data.tag;
				cout << "插入到 L2 的位置：";
				cin >> i;
				data.i = i;
				InsertElem(L2, i, data);
				cout << "目前 L2 路线图：";
				DispLoad(L2);
			}
			
		}
		else if (in == 2) // 删除
		{
			int t = 0;
			cout << "给 L1 删除站点：" << 1 << endl;
			cout << "给 L2 删除站点" << 2 << endl;
			cin >> t;
			if (t == 1)
			{
				int i;
				Elem data = {};
				string name;
				cout << "删除站的名称：";
				cin >> name;
				DeleteByName(L1, name, data);
				cout << "目前 L1 路线图：" << endl;
				DispLoad(L1);
				cout << "删去的站点：" << endl;
				DispElem(&data);
			}
			else if (t == 2)
			{
				int i;
				Elem data = {};
				string name;
				cout << "删除站的名称：";
				cin >> name;
				DeleteByName(L2, name, data);
				cout << "目前 L2 路线图：" << endl;
				DispLoad(L2);
				cout << "删去的站点：" << endl;
				DispElem(&data);
			}
		}
		else if (in == 3) // 修改
		{
			continue;
		}
		else if (in == 4) // 查站点
		{
			continue;
		}
		else if (in == 5) // 查路线
		{
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
		}
	}
	return 0;
}