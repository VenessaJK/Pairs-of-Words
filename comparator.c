#include "main.h"

int comparator(const void* x, const void* y){
    struct sortedNodes *a = (struct sortedNodes *)x;
    struct sortedNodes *b = (struct sortedNodes *)y;

    return(((struct countNode*)b->value)->occur - ((struct countNode*)a->value)->occur);
}