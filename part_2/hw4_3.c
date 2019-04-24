#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int list_of_args[1000];
void *quicksort(void *vargp);
int num_of_args;
int partition (int arr[], int low, int high);
void swap(int* a, int* b);

struct quick_sort{
	int arr [500];
	int start;
	int end;
};

struct quick_sort* addQuickSort(int arr [500], int start, int end){
	struct quick_sort* newQuickSort = (struct quick_sort*)malloc(sizeof(struct quick_sort));
	newQuickSort -> arr == arr;
	newQuickSort -> start = start; 
	newQuickSort -> end = end;
	return newQuickSort;
}

int main (int argc, char** argv)
{
	char* filename = *(argv+1);
	FILE* fPointer;
	struct quick_sort* quick = NULL;

	fPointer = fopen(filename, "r");
	
	//int num_of_args;
	int arg;
	pthread_t thread_id;
	
	fscanf(fPointer, "%d", &num_of_args);
	
	if (num_of_args < 0){fprintf(stderr, "Must have at least 1 number\n");}
	
	for (int i = 0; i < num_of_args; i++){
		fscanf(fPointer, "%d", &arg);
		list_of_args[i] = arg;
	}
	
	quick = addQuickSort(list_of_args, 0, num_of_args - 1);

	pthread_create(&thread_id, NULL, quicksort, (void*) quick);
	pthread_join(thread_id, NULL);
	return 0;
}

void *quicksort(void *vargp){
	int low = (int*) vargp -> start;
	int high = (int*) vargp -> end; 
	pthread_t thread1;
	pthread_t thread2; 

	if (low < high){
		int pi = partition(vargp->arr, low, high);
		vargp -> end = pi - 1;
		pthread_create(&thread1, NULL, quicksort, (void*) vargp);
		vargp -> start = pi + 2;
		pthread_create(&thread2, NULL, quicksort, (void*) vargp);
		pthread_join(thread1, NULL);
		pthread_join(thread2, NULL);


	}
}

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
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
