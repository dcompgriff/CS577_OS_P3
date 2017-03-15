#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

#define BOUND_LIMIT 10

/* Check basic functionality for part 2: should exit cleanly with no output. */
void mRecursiveCall(int);

int
main(int argc, char** argv)
{
	int x[2];
	if ((char*)&x < (char*)(USERTOP - 4096))
		printf(1, "oops [4]\n");
	if (pipe(x) < 0)
		printf(1, "oops [5]\n");

	//Test heap growing until it intersects with the stack.
	//mRecursiveCall(0);

	exit();
}



void mRecursiveCall(int bound){
	if(bound >= BOUND_LIMIT){
		int i;
		char* heapData;// = (char*)malloc(4096*sizeof(char));
		for(i = 0; i < USERTOP; i++){
			//Intentional memory leak to test heap bounding limit size.
			heapData = (char*)malloc(sizeof(char));
			if(!heapData){
				printf(1, "Heap allocation failed at %d!\n", i);
				break;
			}
			//printf(1, "Iteration %d, memory address %d\n", i, (int)(y[i]));
		}
	}else{
		int i;
		volatile char blob[4096];
		for (i = 0; i < sizeof(blob); i++)
			blob[i] = 0;
		mRecursiveCall(bound+1);
	}
}
