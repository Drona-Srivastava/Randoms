#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER 5

int buffer[BUFFER];
int count = 0;
sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void* producer(void *param){
	int item;
	while(1){
		item = rand() % 100;
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		
		buffer[count++] = item;
		printf("Producer produced item %d\n",item);
		
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
		
		sleep(1);
	}
}

void* consumer(void* param){
	int item;
	while(1){
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		
		item = buffer[--count];
		printf("Consumer has consumed item %d\n",item);
		
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
		
		sleep(2);
	}
}

int main(){
	pthread_t prod,cons;
	pthread_mutex_init(&mutex,NULL);
	sem_init(&empty,0,BUFFER);
	sem_init(&full,0,0);
	
	pthread_create(&prod,NULL,producer,NULL);
	pthread_create(&cons,NULL,consumer,NULL);
	
	pthread_join(prod,NULL);
	pthread_join(cons,NULL);
	
	pthread_mutex_destroy(&mutex);
	sem_destroy(&empty);
	sem_destroy(&full);
}