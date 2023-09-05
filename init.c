#include "main.h"

struct hashTable init(){
    struct hashTable h;
    h.table = calloc(TABLESIZE, sizeof(struct node*));
    h.tableSize = 5; 
    h.numOfNodes = 0;   // will keep track of num of nodes in entire table
    return h; 
}