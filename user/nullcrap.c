#include "types.h"
#include "user.h"



int main(void){

    //int mArg = 0;
    int *pmArg = (int*)4096;

    //No error on print.
    printf(1, "Bottom mem space At %d: %d\n", pmArg, *pmArg);
    //No error on print.
    //printf(1, "Top stack At %d.\n", 20996);
    //int *i;
    //for(i = &mArg; i < (int*)21000; i+=4){
    //    printf(1, "Last valid stack addr: %d, %d\n", i, *i);
    //}

    //Error on print.
    //printf(1, "At 20480: %d\n", *(int*)(20480));
    //Error on print.
    //printf(1, "At 4095: %d\n", *(int*)4095);
    //Error on print.
    printf(1, "At 0x0: %d\n", *(int*)0);
    exit();
}






