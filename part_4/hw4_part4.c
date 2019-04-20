#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <semaphore.h>
#include <pthread.h>
#include <ctype.h>
#include <stdint.h>

int museum_ds[500];
pthread_t museum_threads[500];
int museum_threads_count = 0;
char *strlwr(char *str);
void *visitor_in(void *vargp);
void *museum_info(void *vargp);

int main (int argc, char** argv)
{
	int exit_flag = 0;
	char input_line[255];
	char* found;
	char* array[100];
	char command[255];
	char input_find[255];

	do{
		sleep(1);
		printf("shell> ");
		fgets(input_line, 255, stdin);
		strtok(input_line, "\n");
		
		strcpy(input_find, input_line);	
		found = strtok(input_find, " ");
		array[0] = strdup(found);
		array[1] = NULL;
		array[0] = strlwr(array[0]);
	
	
		if (strcmp(array[0], "in") == 0){
			int museum_number = 0;
			int num_visitors = 0;
			pthread_t thread_id;
			
			sscanf(input_line, "%*s %d %d", &museum_number, &num_visitors);
			
			for (int i = 0; i < num_visitors; i++){
				pthread_create(&thread_id, NULL, visitor_in, (void *)(uintptr_t)museum_number);
				museum_threads[museum_threads_count] = thread_id;	
				museum_threads_count++;
			}
			
		}	
		else if (strcmp(array[0], "out")==0){
			int museum_number = 0;
                	int num_visitors = 0;
			int count_one = 0;
                        pthread_t thread_id;
  
                        sscanf(input_line, "%*s %d %d", &museum_number, &num_visitors);

			for (int i = 0; i < museum_threads_count; i++){
				if (museum_threads[i] > 0){
					museum_threads[i] = 0;
					count_one++;
				}
				if (count_one >= num_visitors){
					break;
				}
	
			}			
			
			for (int i = 0; i < num_visitors; i++){
				museum_ds[museum_number]--;
			}	

		}
		else if (strcmp(array[0], "info")==0){
			pthread_t thread_id;
			pthread_create(&thread_id, NULL, museum_info, NULL);

		}
		else if (strcmp(array[0], "start")==0){
		
		}
		else if (strcmp(array[0], "exit")==0){
			exit_flag = 1;	
			exit(0);	
		}
		else{
			fprintf(stderr, "Command invalid\n");
		}	
		
	
	} while (exit_flag == 0);

}

void *visitor_in(void *vargp){
	int mus_num = 0;
	int is_alive;
	mus_num = (uintptr_t)vargp;
	museum_ds[mus_num]++;

	while(1){
		is_alive = 0;
		for (int i = 0; i < museum_threads_count; i++){
			if (museum_threads[i] == pthread_self()){
				is_alive = 1;
			}
		}
		if (is_alive == 0){
			pthread_exit(NULL);
			sleep(1);
		}
	}
}

void *museum_info(void *vargp){
	for (int i = 1; i < 6; i++){
		printf("%d\t", i);
		printf("%d\t", museum_ds[i]);
		if (museum_ds[i] > 0){
			printf("OPEN\n");
		}
		else{
			printf("CLOSE\n");
		}
	}

}

char *strlwr(char *str){
	unsigned char *p = (unsigned char *)str;

	while (*p) {
		*p = tolower((unsigned char)*p);
		p++;
  	}

  	return str;
}
