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
		int in = 0;
		cout << "����վ�������" << 1 << endl;
		cout << "ɾ��վ�������" << 2 << endl;
		cout << "�޸�վ�������" << 3 << endl;
		cout << "��ѯվ�������" << 4 << endl;
		cout << "��ѯ·�߲�����" << 5 << endl;
		cout << "������룺" ;
		cin >> in;
		if (in == 1) //����
		{
			int t = 0;
			cout << "�� L1 ����վ�㣺" << 1 << endl;
			cout << "�� L2 ����վ��" << 2 << endl;
			cin >> t;
			if (t == 1)
			{
				int i;
				Elem data = {};
				cout << "����վ�����ƣ�" ;
				cin >> data.name;
				cout << "����վ��ǰһվ�ľ��룺";
				cin >> data.length;
				cout << "����վ�Ƿ�Ϊ����վ��";
				cin >> data.tag;
				cout << "���뵽 L1 ��λ�ã�" ;
				cin >> i;
				data.i = i;
				InsertElem(L1, i, data);
				cout << "Ŀǰ L1 ·��ͼ��";
				DispLoad(L1);
			}
			else if (t == 2)
			{
				int i;
				Elem data = {};
				cout << "����վ�����ƣ�";
				cin >> data.name;
				cout << "����վ��ǰһվ�ľ��룺";
				cin >> data.length;
				cout << "����վ�Ƿ�Ϊ����վ��";
				cin >> data.tag;
				cout << "���뵽 L2 ��λ�ã�";
				cin >> i;
				data.i = i;
				InsertElem(L2, i, data);
				cout << "Ŀǰ L2 ·��ͼ��";
				DispLoad(L2);
			}
			
		}
		else if (in == 2) // ɾ��
		{
			int t = 0;
			cout << "�� L1 ɾ��վ�㣺" << 1 << endl;
			cout << "�� L2 ɾ��վ��" << 2 << endl;
			cin >> t;
			if (t == 1)
			{
				int i;
				Elem data = {};
				string name;
				cout << "ɾ��վ�����ƣ�";
				cin >> name;
				DeleteByName(L1, name, data);
				cout << "Ŀǰ L1 ·��ͼ��" << endl;
				DispLoad(L1);
				cout << "ɾȥ��վ�㣺" << endl;
				DispElem(&data);
			}
			else if (t == 2)
			{
				int i;
				Elem data = {};
				string name;
				cout << "ɾ��վ�����ƣ�";
				cin >> name;
				DeleteByName(L2, name, data);
				cout << "Ŀǰ L2 ·��ͼ��" << endl;
				DispLoad(L2);
				cout << "ɾȥ��վ�㣺" << endl;
				DispElem(&data);
			}
		}
		else if (in == 3) // �޸�
		{
			continue;
		}
		else if (in == 4) // ��վ��
		{
			continue;
		}
		else if (in == 5) // ��·��
		{
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
		}
	}
	return 0;
}