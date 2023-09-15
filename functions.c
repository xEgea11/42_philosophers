#include <stdio.h> 
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

#define FREE 0;
#define TAKEN 1;

int fork = FREE;
pthread_mutex_t mutex;

//Routine to initialize a thread
void  *print_message()
{
    printf("Hi im thread 1\n"); // See this, how to pass arguments
    return NULL;
}


//Function to modify a critical region
void *take_fork()
{
    pthread_mutex_lock(&mutex);
    printf("Mutex locked for me :D \n");
    fork = TAKEN;
    printf("I've taken the fork, its state: %i\n", fork);
    fork = FREE;
    printf("Now i've freed the fork, its state: %i\n", fork);
    pthread_mutex_unlock(&mutex);
    printf("Mutex unlocked\n");
    return NULL;

}

int main(void)
{
    /*
        Function to get miliseconds
    */
    /*struct timeval milis;

    gettimeofday(&milis, NULL);

    printf("Microseconds: %i\n", milis.tv_usec);
    */


    /*
        Use of threads and initializing them 
    */
    pthread_t thread1, thread2, thread3;
    int i = pthread_create(&thread1, NULL, print_message, NULL); //Get the correct sintax here
    pthread_join(thread1, NULL);
    printf("State of thread creation: %i\n", i);
    printf("Now lets create and initialize a mutex: \n");
    pthread_mutex_init(&mutex, NULL);
    printf("Mutex created...Starting routine to create threads who will take the fork:\n");

    int j = pthread_create(&thread2, NULL, take_fork, NULL);
    pthread_join(thread2, NULL);
    printf("Success: returning value for thread 2: %i\n", j);

    int k = pthread_create(&thread3, NULL, take_fork, NULL);
    pthread_join(thread3, NULL);
    printf("Success: returning value for thread 2: %i\n", k);

}