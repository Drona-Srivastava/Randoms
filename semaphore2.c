#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define Philosophers 5

sem_t Sticks[Philosophers];
pthread_mutex_t monitor;

void* philosopher(void* num){
	int id = *(int*)num;
	while(1){
		printf("Philosopher %d is thinking.\n",id);
		sleep(1);
		
		pthread_mutex_lock(&monitor);
		sem_wait(&Sticks[id]);
		sem_wait(&Sticks[(id+1)%Philosophers]);
		pthread_mutex_unlock(&monitor);
		
		printf("Philosopher %d is eating.\n",id);
		sleep(2);
		
		sem_post(&Sticks[id]);
		sem_post(&Sticks[(id+1)%Philosophers]);
	}
}

int main(){
	pthread_t philo[Philosophers];
	int ids[Philosophers];
	
	pthread_mutex_init(&monitor,NULL);
	for(int i=0;i< Philosophers;i++){
		sem_init(&Sticks[i],0,1);
		ids[i] = i;
	}
	
	for(int i=0;i<Philosophers;i++){
		pthread_create(&philo[i],NULL,philosopher,&ids[i]);
	}
	
	for(int i=0;i<Philosophers;i++){
		pthread_join(philo[i],NULL);
	}
	
	pthread_mutex_destroy(&monitor);
	for(int i=0;i<Philosophers;i++){
		sem_destroy(&Sticks[i]);
	}
}