#include "main.h"

struct hashTable insert(struct hashTable hash, char* key, void* val){
    int index, i=0, listlen;
    unsigned long long hashNum;
    
    //hash the pair of words 
    hashNum = crc64(key);
    index = hashNum%hash.tableSize;

    if (hash.table[index] == NULL){
        hash.table[index] = malloc(sizeof(struct node));

        hash.table[index]->wordPair = malloc((strlen(key)+1)*sizeof(char));
        strcpy(hash.table[index]->wordPair, key);
        hash.table[index]->value = val;
        hash.table[index]->hashOutput = hashNum;
        hash.table[index]->next = NULL;
    }else{
        struct node *new, *temp = hash.table[index];
        new = malloc(sizeof(struct node));

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new;
        new->wordPair = malloc((strlen(key)+1)*sizeof(char));
        strcpy(new->wordPair, key);
        new->value = val;
        new->hashOutput = hashNum;
        new->next = NULL;
    }

    listlen = bucketSize(hash.table, index);
    if (listlen > hash.tableSize){
        int ttlnumofnodes = hash.numOfNodes;
        hash = grow(hash);
        hash.numOfNodes = ttlnumofnodes;
    }
    // if table was grown, this index loses meaning 
    // bc there will be new data written at the index
    return hash;
}

int bucketSize(struct node** table, int index){
    struct node* temp = table[index];
    int i = 0;

    while(temp != NULL){
        i++;
        temp = temp->next;
    }
    return i;
}
