#pragma once
using namespace std;
typedef struct
{
    int i;
    char name[60];
    float length;
    char tag;
} Elem;

typedef struct Node
{
    Elem * data;
    struct Node* next; // ∫Û“ª’æ
} LoadNode;

void CreateLoad1(LoadNode*& L, Elem data[], int n);

void CreateLoad2(LoadNode*& L, Elem data[], int n);

void DispLoad(LoadNode* L);

void DispElem(Elem* data);

bool InsertElem(LoadNode*& L, int i, Elem data);

bool DeleteById(LoadNode*& L, int i, Elem& data);

bool DeleteByName(LoadNode*& L, string name_delete, Elem& data_deleted);

bool AmendElem(LoadNode*& L, string name, Elem data);

bool LocateElemByName(LoadNode* L, string name, LoadNode*& e);

bool LocateElemByTag(LoadNode* L, char tag, LoadNode*& e);

void InFile(string file);

void OutFile(string file, Elem data[], int n);

bool Locate(LoadNode* L, string name);

double LengthSum(LoadNode* be, LoadNode* CNode);

void Suggestion2(string begin, string end, LoadNode* L1, LoadNode* L11, LoadNode* L2, LoadNode* L22);