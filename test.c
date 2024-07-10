#include "philosophers.h"

int main (void)
{
    pthread_mutex_t mutex;

    pthread_mutex_init(&mutex, NULL);

    pthread_mutex_lock(&mutex);
    pthread_mutex_unlock(&mutex);



    pthread_mutex_destroy(&mutex);
}