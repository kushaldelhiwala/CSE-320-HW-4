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
pthread_t museum_one[500];
int museum_one_count = 0;
pthread_t museum_two[500];
int museum_two_count = 0;
pthread_t museum_three[500];
int museum_three_count = 0;
pthread_t museum_four[500];
int museum_four_count = 0;
pthread_t museum_five[500];
int museum_five_count = 0;

char *strlwr(char *str);
void *visitor_thread(void *vargp);
void *info_thread(void *vargp);

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
				pthread_create(&thread_id, NULL, visitor_thread, (void *)(uintptr_t)museum_number);
				switch (museum_number)
				{
					case 1:
						museum_one[museum_one_count] = thread_id;
						museum_one_count++;
						break;
	
					case 2:
						museum_one[museum_one_count] = thread_id;
						museum_two_count++;
						break;
	
					case 3:
						museum_three[museum_three_count] = thread_id; 
						museum_three_count++;
						break;
	
					case 4:
						museum_four[museum_four_count] = thread_id;
						museum_four_count++;
						break;
	
					case 5:
						museum_five[museum_five_count] = thread_id;
						museum_five_count++;
						break;
					
					default:
						break;	
				}
				
	
			}
			
		}	
		else if (strcmp(array[0], "out")==0){
			int museum_number = 0;
                	int num_visitors = 0;
                        pthread_t thread_id;
  
                        sscanf(input_line, "%*s %d %d", &museum_number, &num_visitors);	

			
		}
		else if (strcmp(array[0], "info")==0){
			pthread_t thread_id;
			pthread_create(&thread_id, NULL, info_thread, NULL);

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

void *visitor_thread(void *vargp){
	int mus_num = 0;
	mus_num = (uintptr_t)vargp;
	museum_ds[mus_num]++;

	while(1);
}

void *info_thread(void *vargp){
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
