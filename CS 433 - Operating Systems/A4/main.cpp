/*******************************
  Name: Alec Guilin
  Date: 11/21/19
  CS 433 Assignment 4
 *******************************/
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h> 
#include <time.h> 
#include <unistd.h>
#include "buffer.h"

//semaphores needed for syncronization
pthread_mutex_t mutex;	//mutex lock
sem_t full;				//full sempahore
sem_t empty;			//empty semaphore

//foward declaration
int insertItem(buffer_item item);
int removeItem(buffer_item *item);
void display();

//PURPOSE: produces an item in buffer
//PARAMETER: *param is used to pass pthread_create function
void* producer(void *param)
{
	buffer_item item;

	while (true) {
		sleep(rand() % 3);				//alternates between sleeping and producing
		item = rand() % RAND_MAX;		//generate random number for item

		sem_wait(&empty);				//acquire the semaphore and wait till not full
		pthread_mutex_lock(&mutex);		//enforce the mutex to access critical section

		//CRITICAL SECTION 
		if (insertItem(item) == 0) {
			std::cout << "produced " << item << ". \t";
			display();
		}
		else {
			std::cout << "ERROR: Not able to produce...\n";
		}
		//END OF CRITICAL SECTION

		pthread_mutex_unlock(&mutex);	//unlock the mutex
		sem_post(&full);				//release the semaphore and increment full
	}
}

// PURPOSE: consumes an item in the buffer
// PARAMETER: *param is used to pass pthread_create function
void *consumer(void *param)
{
	buffer_item item;

	while (true) {
		sleep(rand() % 3);				//alternates between sleeping and consuming
		sem_wait(&full);				//acquire the semaphore and wait til not empty
		pthread_mutex_lock(&mutex); 	//enforce the mutex to access critical section

		//CRITICAL SECTION
		if (removeItem(&item) == 0) {
			std::cout << "consumed " << item << ". \t";
			display();
		}
		else {
			std::cout << "ERROR: Not able to consume...\n";
		}
		//END OF CRITICAL SECTION

		pthread_mutex_unlock(&mutex);	//unlock the mutex
		sem_post(&empty);				//release the semaphore then decrement empty
	}
}

int main(int argc, char *argv[])
{
	//input handling
	if (argc < 4 || argc > 4) {
		std::cout << "\n***INPUT ERROR***\nPlease enter the correct parameters when running the program.\nExample: ./run 10 5 5\n\n";// << std::endl;
		exit(1);
	}

	srand(time(NULL));

	//1. get command line arguments argv[1], argv[2], argv[3]
	int sleeptime = atoi(argv[1]);		//1st arg is the sleep time
	int pthreadc = atoi(argv[2]);		//2nd arg is the # of producer threads
	int cthreadc = atoi(argv[3]);		//3rd arg is the # of consumer threads

	//2. initialize buffer / threads / semaphores
	pthread_t producer_threads[pthreadc];
	pthread_t consumer_threads[cthreadc];
	pthread_mutex_init(&mutex, NULL);
	sem_init(&empty, 0, BUFFER_SIZE);	//empty initialized to buffer size
	sem_init(&full, 0, 0);				//full initialized to 0

	//3. create producer thread(s)
	for (int i = 0; i < pthreadc; i++)
		pthread_create(&producer_threads[i], NULL, producer, NULL);

	//4. create consumer thread(s)
	for (int i = 0; i < pthreadc; i++)
		pthread_create(&consumer_threads[i], NULL, consumer, NULL);

	//5. sleep 
	sleep(sleeptime);

	std::cout << "\nThreads completed.\nExiting program.\n\n";

	//6. exit 
	exit(0);
}
