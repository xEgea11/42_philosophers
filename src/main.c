#include "philosophers.h"
#include "table.h"

//./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]

int main(int argc, char *argv[])
{
    t_table *table;
    int i;
    
    if (ft_check_args(argc, argv) == FALSE)
    {
        printf("Arguments are not valid\n");
        return (EXIT_FAILURE);
    }
    if (ft_no_meals_condition(argc, argv) == TRUE)
        return (EXIT_SUCCESS);

    if (ft_one_philo(argv) == TRUE)
    {
        printf("Only one philosopher\n");
        return (EXIT_SUCCESS);
    }
    table = ft_set_table(argc, argv);    
    //Philosophers arrive at dining room and are set up - they start dining there
    ft_greet_philos(&table);

    /* CLEAN TABLE HERE */
    //ft_clean_table(table);
    //Join threads
    i = 0;
    while (i < table->number_philo)
    {
        pthread_join((table->philosophers[i]->thread), NULL);
        i++;
    }
    pthread_join(table->monitor, NULL);
    ft_clean_table(table);
    //Destroy mutexes
    //i = 0;
    //while (i < table->number_philo)
    //{
    //    pthread_mutex_destroy(&table->forks[i]);
    //    i++;
    //}
    //i = 0;
    //while (i < table->number_philo)
    //{
    //    free(table->philosophers[i]);
    //    i++;
    //}
    ////When we declare philos as double array, free the outer array of philos 
    //gettimeofday(&table->end_time, NULL);
    ////End time in ms
    //printf(RED "End time: %ld\n" RESET, ft_time_milis(table->end_time));

    return (EXIT_SUCCESS);
}