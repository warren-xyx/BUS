#pragma once

typedef struct node
{
    int i;
    char name;
    float length;
    struct node* next;
} LoadNode;

void CreateLoad(LoadNode*& L, char name[], float length[], int n);

void InitLoad(LoadNode*& L);

bool InsertElem(LoadNode*& L, int i, char name, float length);

bool DeleteByI(LoadNode*& L, int i, char& name);

bool DeleteByName(LoadNode*& L, char name, int& i);

bool AmendElem(LoadNode*& L, char name, int length);

int LocateByName(LoadNode* L, char name);

char LocateByI(LoadNode* L, int i);

void DispLoad(LoadNode* L);