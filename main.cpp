#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "New.h"
using namespace std;

int main() {
	cout << "������·��ѯ" << endl;
	cout << "����·��¼�л�ȡվ����Ϣ" << endl;

	// ��ʼ��վ��洢�ռ�
	Elem data1[41] = {};
	Elem data2[52] = {};
	int n1 = 41;
	int n2 = 52;
	// �� Load1.txt �ļ��ж�ȡ��һ����·����Ϣ
	OutFile("Load-one.txt", data1, n1);
	OutFile("Load-18.txt", data2, n2);
	// ���� data ������·�� L1
	LoadNode* L1;
	LoadNode* L2;
	LoadNode* L11;
	LoadNode* L22;
	CreateLoad1(L1, data1, n1);
	CreateLoad1(L2, data2, n2);
	CreateLoad2(L11, data1, n1);
	CreateLoad2(L22, data2, n2);
	cout << "�ɹ�������· L1" << endl;
	DispLoad(L1);
	DispLoad(L11);
	cout << "�ɹ�������· L2" << endl;
	DispLoad(L2);
	DispLoad(L22);
	
	while (1)
	{
		cout << "��ѯ·�ߣ�y\n" << "�˳���n" << endl;
		cout << "�Ƿ������ѯ��";
		char t;
		cin >> t;
		if (t == 'n')
			break;

		// ͨ���û����ϳ��³�վ�㣬����������·����
		string begin;
		string end;
		cout << "��������ϳ�վ��" << endl;
		cin >> begin;
		cout << "��������³�վ��" << endl;
		cin >> end;
		Suggestion2(begin, end, L1, L11, L2, L22);
	}
	cout << "ף��˳���죡" << endl;
	cout << L1 << endl;
	return 0;
}