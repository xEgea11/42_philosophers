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
        table->times_must_eat = ft_atol(argv[5]);
    else
        table->times_must_eat = -1;
    
    return (table);
}

void ft_init_mutexes(t_table *table)
{
    int i;

    i = 0;
    while (i < table->number_philo)
    {
        pthread_mutex_init(&table->forks[i], NULL);
        i++;
    }
}
/*
*/
t_table *ft_set_table(int argc, char *argv[])       
{
    t_table *table;
    //int     i;

    table = ft_init_data_table(argc, argv);
    ft_init_mutexes(table);

    return (table);
}

/*                                                                                  <-- Function to free the resources at the end of the program OR when error
*/
void ft_clean_table(t_table *table)
{
    int i;

    i = 0;
    while (i < table->number_philo)
    {
        pthread_mutex_destroy(&table->forks[i]);
        i++;
    }
    free(table->forks);
    i = 0;
    while (i < table->number_philo)
    {
        free(table->philosophers[i]);
        i++;
    }
    free (table->philosophers);
    gettimeofday(&table->end_time, NULL);
    //End time in ms
    printf(RED "Restaurant closed: %ld\n" RESET, ft_time_milis(table->end_time));
    free(table);
}

t_philo *ft_data_init_philo(t_table *table, int id)
{
    t_philo *philo;

    philo = malloc(sizeof(t_philo));

    if (table->times_must_eat != -1)
        philo->times_must_eat = table->times_must_eat;
    else
        philo->times_must_eat = 7;                          //<----------- Hard coded, change that
    philo->id = id;
    philo->dead = FALSE;
    philo->arrived = FALSE;
    philo->can_eat = FALSE;
    philo->full = FALSE;
    philo->times_eaten = 0;
    philo->time_to_die = table->time_to_die;
    philo->time_to_eat = table->time_to_eat;
    philo->time_to_sleep = table->time_to_sleep;
    philo->last_meal = table->start_time; 

    return (philo);
}

void ft_assign_forks(t_table *table, t_philo *philo, int id)
{
    if (id % 2 == 0)
    {
        philo->first_fork = &table->forks[id];
        philo->second_fork = &table->forks[(id + 1) % table->number_philo];
    }
    else
    {
        philo->first_fork = &table->forks[(id + 1) % table->number_philo];
        philo->second_fork = &table->forks[id];
    }
}

t_philo *ft_enter_philo(t_table *table, int id)      //<--- Refactor this one
{
    t_philo *philo;

    philo = ft_data_init_philo(table, id);
    ft_assign_forks(table, philo, id);
    pthread_create(&(philo->thread), NULL, say_hello, (void *)philo);
    return (philo);
}

void    ft_greet_philos(t_table **table)                            
{
    int i;

    gettimeofday(&(*table)->start_time, NULL);
    i = 0;
    while (i < (*table)->number_philo)
    {
        (*table)->philosophers[i] = ft_enter_philo(*table, i);
        i++;
    }
    gettimeofday(&(*table)->start_time, NULL);
    printf(RED "Start time: %ld\n" RESET, ft_time_milis((*table)->start_time)); 
    pthread_create(&(*table)->monitor, NULL, serve, (void *)*table);
}