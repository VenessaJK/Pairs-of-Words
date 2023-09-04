#include "main.h"

struct node* find(struct hashTable hash, char* key){
    int i=0, index;
    struct node* temp;

    index = crc64(key)%hash.tableSize;
    temp = hash.table[index];

    // this bucket is completly empty
    if(temp == NULL) return NULL;
    
    while(temp != NULL){
        if(strcmp(temp->wordPair, key) == 0){
                return temp;
        }
        temp = temp->next;
    }

    // no identical word pair found 
    return NULL;
}