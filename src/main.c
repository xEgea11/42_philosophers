#include "philosophers.h"

//./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]

int main(int argc, char *argv[])
{
    if (ft_check_args(argc, argv) == FALSE)
    {
        printf("Arguments are not valid\n");
        return (EXIT_FAILURE);
    }
    
    t_table *table = ft_set_table(argc, argv);
    int i;
    //pthread_mutex_t print_mutex;              <---Still not set, look if it is necessary

    //We put the initial time here, but it must be put somewhere else
    gettimeofday(&table->start_time, NULL);
    printf(RED "Start time: %ld\n" RESET, ft_time_milis(table->start_time));

    //pthread_mutex_init(&print_mutex, NULL);   <--- In case we need the mutex for the print function 
    
    //Philosophers arrive at dining room and are set up - they start dining there
    ft_greet_philos(&table);

    //Join threads
    i = 0;
    while (i < table->number_philo)
    {
        pthread_join((table->philosophers[i]->thread), NULL);
        i++;
    }

    //Destroy mutexes
    i = 0;
    while (i < table->number_philo)
    {
        pthread_mutex_destroy(&table->forks[i]);
        i++;
    }

    //FREE array of mutexes
    //pthread_mutex_destroy(&print_mutex);
    //philosophers leave the dining room
    i = 0;
    while (i < table->number_philo)
    {
        free(table->philosophers[i]);
        i++;
    }
    //When we declare philos as double array, free the outer array of philos 
    //Clean table 
    //Time when philos end eating at
    gettimeofday(&table->end_time, NULL);
    //End time in ms
    printf(RED "End time: %ld\n" RESET, ft_time_milis(table->end_time));

    return (EXIT_SUCCESS);
}