#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "New.h"
using namespace std;

void CreateLoad1(LoadNode*& L, Elem data[], int n)
{
    LoadNode* s, * r;
    L = (LoadNode*)malloc(sizeof(LoadNode));
    r = L;
    for (int i = 0; i < n; i++)
    {
        s = (LoadNode*)malloc(sizeof(LoadNode));
        s->data = &data[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

void CreateLoad2(LoadNode*& L, Elem data[], int n)
{
    LoadNode* s, * r;
    L = (LoadNode*)malloc(sizeof(LoadNode));
    r = L;
    for (int i = n-1; i >= 0; i--)
    {
        s = (LoadNode*)malloc(sizeof(LoadNode));
        s->data = &data[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

void DispLoad(LoadNode* L)
{
    LoadNode* p = L->next; // p ָ���׽��
    printf(" begin ->\n");
    cout << "---------------------------------------------------------" << endl;
    cout << "| " << "ID" << " | " << setw(30) << "name" << " | " << setw(6) << "length" << " | " << "change" << " |" << endl;
    while (p != NULL)
    {
        cout << "---------------------------------------------------------" << endl;
        cout << "| " << setw(2) << p->data->i << " | " << setw(30) << p->data->name << " | " << setw(6) << p->data->length << " | " << setw(6) << p->data->tag << " |" << endl;
        p = p->next;
    }
    cout << "---------------------------------------------------------" << endl;
    printf(" -> end\n");
}

void DispElem(Elem* data)
{
    cout << "---------------------------------------------------------" << endl;
    cout << "| " << "ID" << " | " << setw(30) << "name" << " | " << setw(6) << "length" << " | " << "change" << " |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "| " << setw(2) << data->i << " | " << setw(30) << data->name << " | " << setw(6) << data->length << " | " << setw(6) << data->tag << " |" << endl;
    cout << "---------------------------------------------------------" << endl;
}

bool InsertElem(LoadNode*& L, int i, Elem data)
{
    int j = 0;
    LoadNode* p = L, * s;
    if (i <= 0)
        return false;
    while (p != NULL && j < i - 1)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        s = (LoadNode*)malloc(sizeof(LoadNode));
        s->data = &data;
        s->next = p->next;
        p->next = s;
        s = s->next;
        while (s != NULL)
        {
            s->data->i += 1;
            s = s->next;
        }
        return true;
    }
}
// ͨ��վ���ɾ��վ�㣬�ɹ�ɾ����data_deletedβɾ���ڵ���Ϣ
bool DeleteById(LoadNode*& L, int i, Elem& data_deleted)
{
    int j = 0;
    LoadNode* p = L, * q;
    if (i <= 0)
        return false;
    while (p != NULL && j < i - 1)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        q = p->next;
        if (q == NULL)
            return false;
        data_deleted = *q->data;
        p->next = q->next;
        free(q);
        p = p->next;
        while (p != NULL)
        {
            p->data->i -= 1;
            p = p->next;
        }
        return true;
    }
}

bool DeleteByName(LoadNode*& L, string name_delete, Elem& data_deleted)
{
    int j = 0;
    LoadNode* p = L, * q;
    while (p != NULL && p->next->data->name!=name_delete)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        q = p->next;
        data_deleted = *q->data;
        p->next = q->next;
        free(q);
        p = p->next;
        while (p != NULL)
        {
            p->data->i -= 1;
            p = p->next;
        }
        return true;
    }
}

// �޸�վ����Ϣ��ͨ��վ������
bool AmendElem(LoadNode*& L, string name, Elem data)
{
    int j = 0;
    LoadNode* p = L->next;
    while (p != NULL && p->data->name!=name)
    {
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        p->data = &data;
        return true;
    }
}

// ����ĳһվ�㣬����������Ϊ�Ƿ񻻳˵�����
bool LocateElemByName(LoadNode* L, string name, LoadNode*& e)
{
    LoadNode* p = L->next;
    while (p != NULL && p->data->name != name)
    {
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        e = p;
        return true;
    }
}

bool LocateElemByTag(LoadNode* L, char tag, LoadNode*& e)
{
    LoadNode* p = L->next;
    while (p != NULL && p->data->tag != tag)
    {
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        e = p;
        return true;
    }
}

bool Locate(LoadNode* L, string name)
{
    LoadNode* p = L->next;
    while (p != NULL && p->data->name != name)
    {
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
        return true;
}

// ����Ϊ��λ��txt�ļ�д��վ������
void InFile(string file)
{
    float length;
    char change;
    char data[100] = {};

    ofstream outfile;
    outfile.open(file, ios::app);

    cout << "Writing to the file" << endl;
    cout << "Enter name";
    cin.getline(data, 40);
    outfile << data << endl;
    cout << "Enter length";
    cin >> length;
    cin.ignore();
    outfile << length << endl;
    cout << "Enter change";
    cin >> change;
    cin.ignore();
    outfile << change << endl;
    outfile.close();
}

// ����Ϊ��λ��ȡtxt�ļ���վ����Ϣ
// .name .length .tag ���������޸�
void OutFile(string file, Elem data[], int n)
{
    ifstream infile;
    infile.open(file);

    cout << "Reading from the " << file << endl;

    for (int i = 0; i < n; i++)
    {
        data[i].i = i+1;
        infile >> data[i].name;
        infile >> data[i].tag;
        infile >> data[i].length;
    }

    infile.close();
}
/*
* // ���� begin �� end ����һ���õĽ���
void Suggestion(string begin, string end, LoadNode* L1, LoadNode* L11, LoadNode* L2, LoadNode* L22)
{
    // �ҵ� L1��L2 �еĻ���վ��
    LoadNode* change1, * change2;
    LocateElemByTag(L1, 'y', change1);
    LocateElemByTag(L2, 'y', change2);

    // ��� begin �� end ����һ����
    if (Locate(L1, begin) && Locate(L1, end))
    {
        cout << "->" << "��ֱ�Ӵ�һ���ߵ�" << begin << "�ϳ�" << endl;
        cout << "->" << "���軻�ˣ��ɴ�" << end << "�³�\n" << endl;
        return;
    }

    // ��� begin �� end ���ڶ�����
    if (Locate(L2, begin) && Locate(L2, end))
    {
        cout << "->" << "��ֱ�ӴӶ����ߵ�" << begin << "�ϳ�" << endl;
        cout << "->" << "���軻�ˣ��ɴ�" << end << "�³�\n" << endl;
        return;
    }

    //LoadNode* bn = (LoadNode*)malloc(sizeof(LoadNode));
    //LoadNode* ed = (LoadNode*)malloc(sizeof(LoadNode));
    //LocateElemByName(L1, begin, bn);
    //LocateElemByName(L1, end, ed);

    // ��� begin �� L1��end �� L2
    if (Locate(L1, begin) && Locate(L2, end))
    {  

        cout << "->" << "��ֱ�Ӵ�һ���ߵ�" << begin << "�ϳ�" << endl;
        cout << "->" << "����" << change1->data->name << "���˵�������" << endl;
        cout << "->" << "����ڶ����ߵ�" << end << "�³�\n" << endl;
        return;
    }

    // ��� begin �� L2��end �� L1
    if (Locate(L2, begin) && Locate(L1, end))
    {
        cout << "->" << "��ֱ�ӴӶ����ߵ�" << begin << "�ϳ�" << endl;
        cout << "->" << "����" << change2->data->name << "���˵�һ����" << endl;
        cout << "->" << "�����һ���ߵ�" << end << "�³�\n" << endl;
        return;
    }
}
*/

// �ܺ�����վ���ľ��룬���μ�ÿ��վ����һվ�� length
double LengthSum(LoadNode*be,LoadNode*CNode)
{
    double sumLength = 0;
    LoadNode* p = be->next;
    while (p != NULL&&p->data!=CNode->data)
    {
        sumLength += p->data->length;
        p = p->next;
    }
    sumLength += p->data->length;
    return sumLength;
}

// 
void Suggestion2(string begin, string end, LoadNode* L1, LoadNode* L11, LoadNode* L2, LoadNode* L22)
{
    // ��ͬһ����·
    if (Locate(L1, begin) && Locate(L1, end))
    {
        LoadNode* bn1;
        LoadNode* ed1;
        LocateElemByName(L1, begin, bn1);
        LocateElemByName(L1, end, ed1);
        cout << "->" << "��ֱ�Ӵ� 1 ���ߵ�" << begin << "�ϳ�" << endl;
        cout << "->" << "���軻�ˣ��ɴ�" << end << "�³�\n" << endl;
        if (bn1->data->i < ed1->data->i)
        {
            cout << "��Լ" << LengthSum(bn1,ed1) << endl;
        }
        else
        {
            cout << "��Լ" << LengthSum(ed1, bn1) << endl;
        }
        
        return;
    }
    if (Locate(L2, begin) && Locate(L2, end))
    {
        LoadNode* bn1;
        LoadNode* ed1;
        LocateElemByName(L2, begin, bn1);
        LocateElemByName(L2, end, ed1);
        cout << "->" << "��ֱ�Ӵ� 18 ���ߵ�" << begin << "�ϳ�" << endl;
        cout << "->" << "���軻�ˣ��ɴ�" << end << "�³�\n" << endl;
        if (bn1->data->i < ed1->data->i)
        {
            cout << "��Լ" << LengthSum(bn1, ed1) << endl;
        }
        else
        {
            cout << "��Լ" << LengthSum(ed1, bn1) << endl;
        }
        return;
    }
    // ����ͬһ����·
    if (Locate(L1, begin) && Locate(L2, end))
    {
        LoadNode* bn1;
        LoadNode* bn11;
        LocateElemByName(L1, begin, bn1);
        LocateElemByName(L11, begin, bn11);
        LoadNode* ed1;
        LoadNode* ed11;
        LocateElemByName(L2, end, ed1);
        LocateElemByName(L22, end, ed11);

        LoadNode* change1, * change2;
        
        cout << "->" << "��ֱ�Ӵ�һ���ߵ�" << begin << "�ϳ�" << endl;
        if (LocateElemByTag(bn1, 'y', change1))
        {
            cout << "->" << "����" << change1->data->name << "���˵�������" << endl;
            cout << "��Լ"<< LengthSum(bn1,change1) <<endl;
        }
        else if(LocateElemByTag(bn11, 'y', change1))
        {
            cout << "->" << "����" << change1->data->name << "���˵�������" << endl;
            cout << "��Լ" << LengthSum(bn11, change1)+bn11->data->length-change1->data->length << endl;
        }

        if (LocateElemByName(ed1, change1->data->name, change2))
        {
            cout << "->" << "����ڶ����ߵ�" << end << "�³�\n" << endl;
            cout << "��Լ" << LengthSum(ed1, change2) + ed1->data->length << endl;
        }
        else if (LocateElemByName(ed11, change1->data->name, change2))
        {
            cout << "->" << "����ڶ����ߵ�" << end << "�³�\n" << endl;
            cout << "��Լ" << LengthSum(ed11, change2) + ed11->data->length - change2->data->length << endl;
        }
        return;
    }

    // ��� begin �� L2��end �� L1
    if (Locate(L1, end) && Locate(L2, begin))
    {
        LoadNode* bn1;
        LoadNode* bn11;
        LocateElemByName(L2, begin, bn1);
        LocateElemByName(L22, begin, bn11);
        LoadNode* ed1;
        LoadNode* ed11;
        LocateElemByName(L1, end, ed1);
        LocateElemByName(L11, end, ed11);

        LoadNode* change1, * change2;

        cout << "->" << "��ֱ�Ӵ� 18 ���ߵ�" << begin << "�ϳ�" << endl;
        if (LocateElemByTag(bn1, 'y', change1))
        {
            cout << "->" << "����" << change1->data->name << "���˵� 1 ����" << endl;
            cout << "��Լ" << LengthSum(bn1, change1) << endl;
        }
        else if (LocateElemByTag(bn11, 'y', change1))
        {
            cout << "->" << "����" << change1->data->name << "���˵� 1 ����" << endl;
            cout << "��Լ" << LengthSum(bn11, change1)+bn11->data->length-change1->data->length << endl;
        }

        if (LocateElemByName(ed1, change1->data->name, change2))
        {
            cout << "->" << "����� 1 ���ߵ�" << end << "�³�\n" << endl;
            cout << "��Լ" << LengthSum(ed1, change2) + ed1->data->length << endl;
        }
        else if (LocateElemByName(ed11, change1->data->name, change2))
        {
            cout << "->" << "����� 1 ���ߵ�" << end << "�³�\n" << endl;
            cout << "��Լ" << LengthSum(ed11, change2) + ed11->data->length- change2->data->length << endl;
        }
        return;
    }

}