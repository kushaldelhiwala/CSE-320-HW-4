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

// Note: some code reused from previous homework

void *hire_thread(void *vargp);
pthread_t child_thread[500];
int child_pos = 0;
char *strlwr(char *str);

int main (int argc, char** argv)
{
	int exit_flag = 0;
	char input_line[255];
	char* found;
	char* array[100];
	char command[255];
	char input_find[255];

	do{
		printf("shell> ");
		fgets(input_line, 255, stdin);
		strtok(input_line, "\n");
		
		strcpy(input_find, input_line);	
		found = strtok(input_find, " ");
		array[0] = strdup(found);
		array[1] = NULL;
		array[0] = strlwr(array[0]);	
	
		if (strcmp(array[0], "help")==0){
			printf("Here are the functions of the various commands\n");
			printf("Hire: You can hire artists\n");
			printf("Fire: You can fire artists\n");
			printf("FireAll: You can fire all artists\n");
			printf("List: List all the artists PIDs\n");
			printf("Exit: Exit the program\n");
		}	
		
		else if(strcmp(array[0], "hire")==0){
			int num_of_threads = 0;
			sscanf(input_line, "%*s %d", &num_of_threads);
			pthread_t thread_id;
	
			for (int i = 0; i < num_of_threads; i++){
				 pthread_create(&thread_id, NULL, hire_thread, NULL);
				 child_thread[child_pos] = thread_id;
				 child_pos++;
			}
		}
		else if(strcmp(array[0], "fire")==0){
			pthread_t thread_id = 0;
			sscanf(input_line, "%*s %ld", &thread_id);
			int match_found = 0;
			
			for (int k = 0; k < child_pos; k++){
				if (child_thread[k] == thread_id){
					match_found = 1;
					child_thread[k] = 0;
				}
			}
		
			if (match_found == 1){}
			
			else{
				fprintf(stderr,"Match not found for ID\n");
			}
			
		}
		else if(strcmp(array[0], "fireall")==0){
			for (int k = 0; k < child_pos; k++){
				if (child_thread[k] > 0){
					child_thread[k] = 0;
	
				}
				
			}
		}
		else if(strcmp(array[0], "list")==0){
			for (int i = 0; i < child_pos; i++){
				if (child_thread[i] > 0){
					printf("%ld\t", child_thread[i]);
					printf("WAITING\n");
				}
			}
		}
		else if(strcmp(array[0], "exit")==0){
                        for (int k = 0; k < child_pos; k++){
   				if (child_thread[k] > 0){
					child_thread[k] = 0;
				}
			
			}
			
			exit_flag = 1;
		}
		
		else{
			fprintf(stderr,"Please enter a valid command\n");
		}
	
	} while(exit_flag==0);

	return 0;

}


void *hire_thread(void *vargp){
	sleep(1);
	int is_alive;
	while(1){
		is_alive = 0;
		for (int k = 0; k < child_pos; k++){
			if (child_thread[k] == pthread_self()){
				is_alive = 1;
			}
		}
		if (is_alive == 0){
			pthread_exit(NULL);
			sleep(1);
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
