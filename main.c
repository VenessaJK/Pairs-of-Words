#include "main.h"

int main(int argc, char** argv){
    int i=0, index;
    char* wordPair, *secondword, *firstword;
    struct node* temp; 

    // checking command line input
    if (argc < 2){
        printf("Not enough arguments\n"); 
        return 1;
    }
    // will need to loop this later to get all files in command line
    char* filename = argv[1];
    
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        printf("File couldn't be opened"); 
        return 1;
    }

    // create hash table
    struct hashTable hash = init();

    // call getNextWord once so loop can work below
    firstword = getNextWord(fp);
    if(firstword == NULL){
        printf("Your file is empty.\n");
        return 1;
    }

    while(fp != NULL){
        strcat(firstword, " ");
        secondword = getNextWord(fp);
        if(secondword == NULL){
            break;
        }
        wordPair = strdup(strcat(firstword, secondword));
        strcpy(firstword, secondword);

        /* find returns a struct node ptr if an identical wordpair is
            found so that I can access that structs node ptrs void*
            if no identical wp is found, returns null */
        if((temp = find(hash, wordPair)) != NULL){  
            // if the wordpair is found just inc occur
            ((struct countNode*)(temp->value))->occur++;
        }else{
            // creating a node to count num of occurances of wordpair
            // count is like a temp var that creates a new struct
            // and just assignes its pointer to a given bucket
            struct countNode* count = malloc(sizeof(struct countNode));
            count->occur = 1;
            // insert the wordpair into table   
            hash = insert(hash, wordPair, count);
            printf("this is the table size in main %d\n", hash.tableSize);
            hash.numOfNodes++;
        }
    }
    printTable(hash.table, hash.tableSize);
    printf("number of total nodes: %d\n", hash.numOfNodes);
    printf("this is the table size %d", hash.tableSize);
    return 0;
}