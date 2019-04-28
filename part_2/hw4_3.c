#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>
// Disclosure: used some code from online to help create the split function

int list_of_args[1000];
void *quicksort(void *vargp);
int split (int arr[], int low, int high);
void swap(int* a, int* b);
void cse320_print(char* message);

struct quick_sort{
	int start;
	int end;
};

int main (int argc, char** argv)
{
	char* filename = *(argv+1);
	FILE* fPointer;
	struct quick_sort quick;
	
	if (argc != 2){
		fprintf(stderr, "You must have a filename to read from\n");
		exit (0);
	}

	fPointer = fopen(filename, "r");
	
	int num_of_args;
	int arg;
	pthread_t thread_id;
	
	fscanf(fPointer, "%d", &num_of_args);
	
	if (num_of_args < 0){fprintf(stderr, "Must have at least 1 number\n");}
	
	for (int i = 0; i < num_of_args; i++){
		fscanf(fPointer, "%d", &arg);
		list_of_args[i] = arg;
	}

	quick.start = 0;
	quick.end = num_of_args - 1;

	pthread_create(&thread_id, NULL, quicksort, &quick);
	pthread_join(thread_id, NULL);
	
	for (int i = 0; i < num_of_args; i++){
		char buffer[500];
		sprintf(buffer, "%d ", list_of_args[i]);
		cse320_print(buffer);
	}
	cse320_print("\n");

	return 0;
}

void *quicksort(void *vargp){
	struct quick_sort *test = vargp;
	int low = test -> start;
	int high = test -> end; 

	if (low < high){
		int pi = split(list_of_args, low, high);
		int token1 = pi - 1;
		int token2 = pi + 1;
		pthread_t thread1;
		pthread_t thread2;
		
		struct quick_sort quick1;
		quick1.start = low;
		quick1.end = token1;

		struct quick_sort quick2;
		quick2.start = token2; 
		quick2.end = high;

		pthread_create(&thread1, NULL, quicksort, &quick1);
		pthread_create(&thread2, NULL, quicksort, &quick2);

		pthread_join(thread1, NULL);
		pthread_join(thread2, NULL);
	
		return NULL;
	}	

}

int split (int arr[], int low, int high) 
{ 
    int pivot = arr[high];     
    int i = (low - 1);   
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;     
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
