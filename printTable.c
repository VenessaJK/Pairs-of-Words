#include "main.h"
// DEBUGGING FUNCTION
void printTable(struct node** table, int tablesize){
    struct node* temp;
    int i=0;

    for(i; i < tablesize; i++){
        temp = table[i];
        while(temp != NULL){
            printf("the wordpair: %s  the count: %d  the index: %llu\n", temp->wordPair, ((struct countNode*)temp->value)->occur, temp->hashOutput); 
            temp = temp->next;
        }
    }
}