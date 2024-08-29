#include "philosophers.h"
#include "table.h"

t_table *ft_init_data_table(int argc, char *argv[])
{
    t_table *table;

    table = malloc(sizeof(t_table));
    table->number_philo = ft_atol(argv[1]);
    table->forks = malloc(sizeof(pthread_mutex_t) * table->number_philo);
    table->philosophers = malloc(sizeof(t_philo *) * table->number_philo);
    table->end_simulation = FALSE;
    table->all_philos_ready = FALSE;
    table->time_to_die = ft_atol(argv[2]);
    table->time_to_eat = ft_atol(argv[3]);
    table->time_to_sleep = ft_atol(argv[4]);
    if (argc == 6)
    {
        table->nbr_meals = TRUE;
        table->times_must_eat = ft_atol(argv[5]);
    }
    else
    {
        table->nbr_meals = FALSE;
        table->times_must_eat = -1;
    }
    
    return (table);
}

t_table *ft_set_table(int argc, char *argv[])       
{
    t_table *table;

    table = ft_init_data_table(argc, argv);
    ft_init_mutexes(table);

    return (table);
}

void ft_clean_table(t_table *table)
{
    int i;

    i = 0;
    while (i < table->number_philo)
    {
        pthread_mutex_destroy(&table->forks[i]);
        i++;
    }
    pthread_mutex_destroy(&table->print_mutex);
    pthread_mutex_destroy(&table->end_simulation_mutex);
    free(table->forks);
    i = 0;
    while (i < table->number_philo)
    {
        pthread_mutex_destroy(&table->philosophers[i]->arrived_mutex);
        pthread_mutex_destroy(&table->philosophers[i]->can_eat_mutex);
        pthread_mutex_destroy(&table->philosophers[i]->full_mutex);
        pthread_mutex_destroy(&table->philosophers[i]->last_meal_mutex);
        free(table->philosophers[i]);
        i++;
    }
    free (table->philosophers);
    gettimeofday(&table->end_time, NULL);
    printf(RED "Restaurant closed: %ld\n" RESET, ft_time_milis(table->end_time, table));        //Remove this 
    free(table);
}

void ft_finish_dinner(t_table *table)
{
    int i;
    
    i = 0;
    while (i < table->number_philo)
    {
        pthread_join((table->philosophers[i]->philo), NULL);
        i++;
    }
    pthread_join(table->monitor, NULL);
}