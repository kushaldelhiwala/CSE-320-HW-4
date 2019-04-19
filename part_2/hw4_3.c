#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int list_of_args[1000];

int main (int argc, char** argv)
{
	char* filename = *(argv+1);
	FILE* fPointer;
	
	fPointer = fopen(filename, "r");
	
	int num_of_args;
	int arg;
	
	fscanf(fPointer, "%d", &num_of_args);
	
	if (num_of_args < 0){fprintf(stderr, "Must have at least 1 number\n");}
	
	for (int i = 0; i < num_of_args; i++){
		fscanf(fPointer, "%d", &arg);
		list_of_args[i] = arg;
	} 

	return 0;
}
