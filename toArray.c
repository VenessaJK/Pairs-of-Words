#include "main.h"

struct sortedNodes* toArray(struct hashTable hash){
    // make an array w/ space for every word pair
    int i=0, j=0;
    struct sortedNodes* sortedTable = malloc(hash.numOfNodes*sizeof(struct sortedNodes));

    for(i; i < hash.tableSize; i++){
        struct node* temporary = hash.table[i];
        while(temporary != NULL){
	    sortedTable[j].wordPair = malloc((strlen(temporary->wordPair)+1)*sizeof(char));
            strcpy(sortedTable[j].wordPair, temporary->wordPair);
            sortedTable[j].value = temporary->value;
            temporary = temporary->next;
            j++;
        }
    }

    return sortedTable;
}
