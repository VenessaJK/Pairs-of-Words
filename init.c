#include "main.h"

struct hashTable init(){
    struct hashTable h;
    h.table = calloc(TABLESIZE, sizeof(struct node*));
    h.tableSize = TABLESIZE; // initial size
    h.numOfNodes = 0;   // will keep track of num of nodes in entire table
    return h; 
}