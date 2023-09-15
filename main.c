//TODO: Make a schema of the code (what goes where)

#include <stdio.h> 
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

//can i use "i" as variable in the define??? ---> YES
#define LEFT (i + number_philo - 1) % number_philo      //  LEFT neighbor 
#define RIGHT (i + 1) % number_philo                    //  RIGHT neighbor
#define THINKING 0
#define HUNGRY 1
#define EATING 2

//Can I define it with the same number as the states?
#define FREE 0
#define TAKEN 1

 
int times_to_eat = 5;
pthread_mutex_t mutex;

//CHECKING IT: each philosopher must take its forks to left and right each time it has to eat,
//print it then return
void take_forks(int times_to_eat, pthread_mutex_t *mutex)
{
    int i = 0;
    while (i < times_to_eat)
    {
        //I Really dont know how to access to some variables from the functions; cannot pass them as arguments
        //since "pthread_create" only accepts 1 parameter to pass to a function..
        //Should we do a struct with everything and pass it as the only argument everytime??
        printf("Attempt %i to get forks:\n", i+1);
        pthread_mutex_lock(mutex);
        printf("Can access to forks:\nUnlocking again...\n");
        forks[i] = TAKEN;                         
        printf("Took the fork %i and I'm eating, yum yum\n", i);
        forks[i] = FREE;
        printf("Enough, i got tons of spaghetti already\n");
        pthread_mutex_unlock(mutex);
        printf("Fork unlocked! The rest can access :D\n");
        i++;
    }
}

//Routine to say hi to the world from each philo
void *say_hi(void *index)
{
    int i = *(int *)index;
    printf("Hello, Im a philosopher %i, Im going to crush your head\n", i);
    take_forks(times_to_eat, &mutex); //HARDCODED, SEE HOW WE CAN PASS THE NUMBER OF TIMES IT MUST EAT
    return NULL;
}

int main(int argc, char *argv[])
{   
   //It allows to enter the critical region (forks); we initialize it....HOW TO PASS IT TO THE THREADS??
   
    pthread_mutex_init(&mutex, NULL);

    //check good number of args; implement others args: time_to_die; time_to_eat, 
    //time_to_sleep
    if (argc != 3)
        return -1;
    
    //Argv[1] number_of_philosophers (and number of forks)
    int number_philo = atoi(argv[1]);   //<<< Dont use these functions; we should code our own

    //Array with each philosopher
    pthread_t philosophers[number_philo];  
    printf("There are %i philosophers\n", number_philo);

    

    //Argv[2] Number of times each philo must eat
    int times_to_eat = atoi(argv[2]);
    printf("Each philosopher must eat %i times\n", times_to_eat);

    //Lets create each philosopher
    int i = 0;
    while(i < number_philo)
    {
        if (pthread_create(&philosophers[i], NULL, say_hi, &i) != 0)
        {
            printf("Error, couldnt initialize\n");
            return -1; 
        }
        pthread_join(philosophers[i], NULL);  //We call join so we wait to every thread to print its index
        i++;
    }

    //Array with forks
    //If there is just one, he has only one fork (he cant eat)
    int forks[number_philo];

    //Lets check the forks
    int j = 0;
    while (j < number_philo)
    {
        forks[j] = FREE;
        if (forks[j] == FREE)
            printf("Fork from philosopher %i is here, and its FREE\n", j);
        else
            printf("Fork from pilosopher %i is TAKEN\n", j);
        j++;
    }
}



