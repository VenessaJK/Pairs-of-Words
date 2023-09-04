#include "main.h"

struct hashTable grow(struct hashTable hash){
    int i=0, newIndex, index;
    // temp old is traversing through the old table
    // temp new is traversing through the new table
    struct node *tempOld, *tempNew, *new; 
    struct hashTable newHash;
    newHash.tableSize = 3*hash.tableSize;
    struct node** newTable = calloc(newHash.tableSize, sizeof(struct node*));

    for(i; i < hash.tableSize; i++){
        // looping through every bucket
        tempOld = hash.table[i];

        // looping through every node in linked list
        while(tempOld != NULL){
            // retrieve cached hash value and mod by new size
            newIndex = tempOld->hashOutput%newHash.tableSize;
            // if newTable at the new index is empty, add node from old table
            if(newTable[newIndex] == NULL){
                // malloc space for first new node
                newTable[newIndex] = malloc(sizeof(struct node*));
            
                // start creating space and assigning data from old table to new
                newTable[newIndex]->wordPair = malloc((strlen(tempOld->wordPair)+1)*sizeof(char));
                strcpy(newTable[newIndex]->wordPair, tempOld->wordPair);
                newTable[newIndex]->value = tempOld->value;
                newTable[newIndex]->hashOutput = tempOld->hashOutput;
                newTable[newIndex]->next = NULL;

            } else{ // the new table it new index is not empty
                tempNew = newTable[newIndex];  
                new = malloc(sizeof(struct node));

                // iterate to end of list at new index
                while(tempNew->next != NULL){
                    tempNew = tempNew->next;
                }

                // attach new node and copy over data
                tempNew->next = new;
                new->wordPair = malloc((strlen(tempOld->wordPair)+1)*sizeof(char));
                strcpy(new->wordPair, tempOld->wordPair);
                new->value = tempOld->value;
                new->hashOutput = tempOld->hashOutput;
                new->next = NULL;
            }

            tempOld = tempOld->next;
        }
    } // end of copying over old table to new table

    newHash.table = newTable;

    printf("this is the new size: %d\n", newHash.tableSize);

    // clean(hash.table);
    return newHash;
}