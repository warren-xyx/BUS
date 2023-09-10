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
    LoadNode* p = L->next; // p 指向首结点
    printf(" begin ->\n");
    cout << "-----------------------------------------------" << endl;
    cout << "| " << "ID" << " | " << setw(20) << "name" << " | " << setw(6) << "length" << " | " << "change" << " |" << endl;
    while (p != NULL)
    {
        cout << "-----------------------------------------------" << endl;
        cout << "| " << setw(2) << p->data->i << " | " << setw(20) << p->data->name << " | " << setw(6) << p->data->length << " | " << setw(6) << p->data->tag << " |" << endl;
        p = p->next;
    }
    cout << "-----------------------------------------------" << endl;
    printf(" -> end\n");
}

void DispElem(Elem* data)
{
    cout << "-----------------------------------------------" << endl;
    cout << "| " << "ID" << " | " << setw(20) << "name" << " | " << setw(6) << "length" << " | " << "change" << " |" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "| " << setw(2) << data->i << " | " << setw(20) << data->name << " | " << setw(6) << data->length << " | " << setw(6) << data->tag << " |" << endl;
    cout << "-----------------------------------------------" << endl;
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
// 通过站点号删除站点，成功删除则data_deleted尾删除节点信息
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

bool DeleteByName(LoadNode*& L, string name_delete, Elem& data_daleted)
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
        data_daleted = *q->data;
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

// 修改站点信息，通过站名搜索
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

// 查找某一站点，后续用来作为是否换乘的依据
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

void OutFile(string file, Elem data[], int n)
{
    ifstream infile;
    infile.open(file);

    cout << "Reading from the file" << endl;

    for (int i = 0; i < n; i++)
    {
        data[i].i = i+1;
        infile >> data[i].name;
        infile >> data[i].length;
        infile >> data[i].tag;
    }

    infile.close();
}
// 根据 begin 和 end 给出一条好的建议
void Suggestion(string begin, string end, LoadNode* L1, LoadNode* L11, LoadNode* L2, LoadNode* L22)
{
    // 找到 L1，L2 中的换乘站点
    LoadNode* change1, * change2;
    LocateElemByTag(L1, 'y', change1);
    LocateElemByTag(L2, 'y', change2);

    // 如果 begin 和 end 都在一号线
    if (Locate(L1, begin) && Locate(L1, end))
    {
        cout << "->" << "请直接从一号线的" << begin << "上车" << endl;
        cout << "->" << "无需换乘，可从" << end << "下车\n" << endl;
        return;
    }

    // 如果 begin 和 end 都在二号线
    if (Locate(L2, begin) && Locate(L2, end))
    {
        cout << "->" << "请直接从二号线的" << begin << "上车" << endl;
        cout << "->" << "无需换乘，可从" << end << "下车\n" << endl;
        return;
    }

    //LoadNode* bn = (LoadNode*)malloc(sizeof(LoadNode));
    //LoadNode* ed = (LoadNode*)malloc(sizeof(LoadNode));
    //LocateElemByName(L1, begin, bn);
    //LocateElemByName(L1, end, ed);

    // 如果 begin 在 L1，end 在 L2
    if (Locate(L1, begin) && Locate(L2, end))
    {  

        cout << "->" << "请直接从一号线的" << begin << "上车" << endl;
        cout << "->" << "并在" << change1->data->name << "换乘到二号线" << endl;
        cout << "->" << "最后在二号线的" << end << "下车\n" << endl;
        return;
    }

    // 如果 begin 在 L2，end 在 L1
    if (Locate(L2, begin) && Locate(L1, end))
    {
        cout << "->" << "请直接从二号线的" << begin << "上车" << endl;
        cout << "->" << "并在" << change2->data->name << "换乘到一号线" << endl;
        cout << "->" << "最后在一号线的" << end << "下车\n" << endl;
        return;
    }
}