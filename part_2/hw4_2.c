#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int number_counter[10];
void *thread(void *vargp);
sem_t mutex;

int main (int argc, char** argv)
{
	FILE *fptr1;
	FILE *fptr2;
	FILE *fptr3;
	pthread_t tid1, tid2, tid3;
	
	fptr1 = fopen("file1.dat", "r");
	fptr2 = fopen("file2.dat", "r");
	fptr3 = fopen("file3.dat", "r");

	if (fptr1 == NULL || fptr2 == NULL || fptr3 == NULL){
		fprintf(stderr, "Issue with files\n");
		exit(-1);
	}
	sem_init(&mutex, 0, 1);

	pthread_create(&tid1, NULL, thread, (void*) fptr1);
    	pthread_create(&tid2, NULL, thread, (void*) fptr2);
	pthread_create(&tid3, NULL, thread, (void*) fptr3);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);	
	pthread_join(tid3, NULL);
	
	printf("%d\t", number_counter[0]);
	printf("%d\t", number_counter[1]);
	printf("%d\n", number_counter[2]);
	
	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);
	sem_destroy(&mutex);

	return 0;
}

void *thread(void *vargp)
{
	int input_num;
	int rando_num;
	
	sem_wait(&mutex);

	fscanf(vargp, "%d", &input_num);	

	number_counter[0] = 0;
	number_counter[1] = 0;
	number_counter[2] = 0;

	for (int i = 0; i < input_num; i++){
		fscanf(vargp, "%d", &rando_num);
		if (rando_num == 0){
			number_counter[0]++;
		}
		else if (rando_num == 1){
			number_counter[1]++;
		}
		else if (rando_num == 2){
			number_counter[2]++;
		}
	}
	sem_post(&mutex);
	pthread_exit(0);	
}

