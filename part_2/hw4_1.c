#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  
#include <pthread.h>
#include <math.h> 
// Note: Some code has been reused from my Homework 3

void *fibonacci_thread(void *vargp);

int main (int argc, char** argv)
{
	pthread_t thread_id;
	
	if (argc != 2){
		fprintf(stderr,"Enter arguments correctly\n");
		exit(-1);
  	}
	
	char* arg_i = *(argv+1);
	
	pthread_create(&thread_id, NULL, fibonacci_thread, (void*) arg_i);
	pthread_join(thread_id, NULL); 
	exit(0);
}

void *fibonacci_thread(void *vargp)
{
	int input_num = 0;
	long long fibonacci_input = 0;

	input_num = atoi(vargp);
	input_num = input_num % 60;
	
	double phi = (1 + sqrt(5)) / 2; 
  	double phi_1 = (1 - sqrt(5)) / 2; 

 	if (input_num > 0){
		fibonacci_input = round(pow(phi, input_num) / sqrt(5));
		printf("%llu\n", fibonacci_input);
	}

  	else{
		fibonacci_input = round(pow(phi_1, input_num) / sqrt(5));
		printf("%llu\n", fibonacci_input);
  	}

}
