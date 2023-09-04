#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "getWord.h"
#include "crc64.h"
#define TABLESIZE 5

struct hashTable{
    struct node** table;
    int tableSize;
    int numOfNodes;
};

struct countNode{
    int occur;
    struct count* next;
};

struct node{
    char *wordPair;
    void *value;
    unsigned long long hashOutput;
    struct node* next;
};

struct hashTable init();
struct node* find(struct hashTable, char*);
struct hashTable insert(struct hashTable, char*, void*);
int bucketSize(struct node**, int);
void printTable(struct node**, int);
struct hashTable grow(struct hashTable);