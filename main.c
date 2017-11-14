#include "sort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N2_SRT_SIZE 10000
#define NLOGN_SRT_SIZE 10000000

#define println(...) do{printf(__VA_ARGS__);printf("\n");}while(0)

TYPE intcmp(TYPE a,TYPE b){
    if(a-b<=0) return -1;
    return 1;
}

void randinitarr(int* arr,int size){
    for(int i=0;i<size;i++){
        arr[i]=rand();
    }
}

void validate(int* arr,int size){
    for(int i=1;i<size;i++){
        if(arr[i-1] > arr[i]){
            println("[ERR] Incorrectly sorted: %d goes before %d.",arr[i-1],arr[i]);
            exit(1);
        }
    }
}

int main(void){
    srand(time(0));
    int smallarr[N2_SRT_SIZE],largearr[NLOGN_SRT_SIZE];
    randinitarr(smallarr,N2_SRT_SIZE);
    println("[TST] Start testing insertion sort with %d elements..",N2_SRT_SIZE);
    clock_t starttime = clock();
    insertion_sort(smallarr,N2_SRT_SIZE,intcmp);
    clock_t delta = clock()-starttime;
    println("[TST] Insertion test finished. Time used %.2lfs.",(delta/(double)CLOCKS_PER_SEC));
    println("[TST] Start validating ..");
    validate(smallarr,N2_SRT_SIZE);
    println("[YES] Insertion test passed.");
    randinitarr(smallarr,N2_SRT_SIZE);
    println("[TST] Start testing bubble sort with %d elements..",N2_SRT_SIZE);
    starttime = clock();
    bubble_sort(smallarr,N2_SRT_SIZE,intcmp);
    delta = clock()-starttime;
    println("[TST] Bubble test finished. Time used %.2lfs.",(delta/(double)CLOCKS_PER_SEC));
    println("[TST] Start validating ..");
    validate(smallarr,N2_SRT_SIZE);
    println("[YES] Bubble test passed.");
    randinitarr(largearr,NLOGN_SRT_SIZE);
    println("[TST] Start testing merge sort with %d elements ..",NLOGN_SRT_SIZE);
    starttime = clock();
    merge_sort(largearr,NLOGN_SRT_SIZE,intcmp);
    delta = clock()-starttime;
    println("[TST] Merge test finished. Time used %.2lfs.",(delta/(double)CLOCKS_PER_SEC));
    println("[TST] Start validating ..");
    validate(largearr,NLOGN_SRT_SIZE);
    println("[YES] Merge test passed.");
    randinitarr(largearr,NLOGN_SRT_SIZE);
    println("[TST] Start testing quick sort with %d elements..",NLOGN_SRT_SIZE);
    starttime = clock();
    quick_sort(largearr,NLOGN_SRT_SIZE,intcmp);
    delta = clock()-starttime;
    println("[TST] Quick test finished. Time used %.2lfs.",(delta/(double)CLOCKS_PER_SEC));
    println("[TST] Start validating ..");
    validate(largearr,NLOGN_SRT_SIZE);
    println("[YES] Quick test passed.");
    println("[YES] All test passed.");
    return 0;
}