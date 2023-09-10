#include <stdio.h>
#include "stdlib.h"
#include "Loadlist.h"

void CreateLoad(LoadNode*& L, char name[], float length[], int n)
{
    LoadNode* s, * r;
    L = (LoadNode*)malloc(sizeof(LoadNode));
    r = L;
    for (int i = 0; i < n; i++)
    {
        s = (LoadNode*)malloc(sizeof(LoadNode));
        s->name = name[i];
        s->length = length[i];
        s->i = i + 1;
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

void InitLoad(LoadNode*& L)
{
    L = (LoadNode*)malloc(sizeof(LoadNode));
    L->next = NULL;
}

bool InsertElem(LoadNode*& L, int i, char name, float length)
{
    int j = 0;
    LoadNode* p = L, * s;
    if (i <= 0)
        return false;
    while (j < i - 1 && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        s = (LoadNode*)malloc(sizeof(LoadNode));
        s->name = name;
        s->length = length;
        s->i = i;
        s->next = p->next;
        p->next = s;
        s = s->next;
        while (s != NULL)
        {
            s->i = i + 1;
            s = s->next;
        }
        return true;
    }
}

bool DeleteByI(LoadNode*& L, int i, char& name)
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
        name = q->name;
        p->next = q->next;
        free(q);
        return true;
    }
}

bool DeleteByName(LoadNode*& L, char name, int& i)
{
    int j = 0;
    LoadNode* p = L, * q, * t;
    while (p != NULL && p->next->name != name)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        i = j + 1;
        q = p->next;
        t = q->next;
        free(q);
        p->next = t;
        while (t != NULL)
        {
            t->i = i - 1;
            t = t->next;
        }
        return true;
    }
}

bool AmendElem(LoadNode*& L, char name, int length)
{
    LoadNode* p = L, * q;
    while (p != NULL && p->name == name)
    {
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        p->length = length;
        return true;
    }
}

int LocateByName(LoadNode* L, char name)
{
    int i = 1;
    LoadNode* p = L->next;
    while (p != NULL && p->name != name)
    {
        p = p->next;
        i++;
    }
    if (p == NULL)
        return 0;
    else
        return p->i;
}


char LocateByI(LoadNode* L, int i)
{
    int j = 0;
    LoadNode* p = L, * q;
    if (i <= 0)
        return false;
    while (p != NULL && j == i)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
        return p->name;
}

void DispLoad(LoadNode* L)
{
    LoadNode* p = L->next; // p 指向首结点
    printf("begin -> ");
    while (p != NULL)
    {
        printf("%c -> ", p->name);
        p = p->next;
    }
    printf("end\n");
}