#include "main.h"

void printArray(struct sortedNodes* sortedTable, int tablesize){
    int i=0;
    while(i < tablesize){
        printf("%10d %s\n", ((struct countNode *)sortedTable[i].value)->occur, sortedTable[i].wordPair);
	i++;
    }
    return;
}
