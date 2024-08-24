#include "philosophers.h"
#include "table.h"

/*
*/
t_table *ft_set_table(int argc, char *argv[])       
{
    t_table *table;
    int     i;

    table = malloc(sizeof(t_table));
    table->end_simulation = FALSE;
    table->number_philo = ft_atol(argv[1]);
    table->forks = malloc(sizeof(pthread_mutex_t) * table->number_philo);
    table->philosophers = malloc(sizeof(t_philo*) * table->number_philo);
    table->time_to_die = ft_atol(argv[2]);
    table->time_to_eat = ft_atol(argv[3]);
    table->time_to_sleep = ft_atol(argv[4]);

    if (argc == 6)
        table->times_must_eat = ft_atol(argv[5]);
    else
        table->times_must_eat = -1;

    //Init mutexes -- setting the table
    i = 0;
    while (i < table->number_philo)
    {
        pthread_mutex_init(&table->forks[i], NULL);
        i++;
    }
    return (table);
}

/*                                                                                  <-- Function to free the resources at the end of the program OR when error
*/
void ft_clean_table(t_table *table)
{
    printf("Hello");


}

t_philo *ft_enter_philo(t_table *table, int i)
{
    t_philo *philo;

    philo = malloc(sizeof(t_philo));

    if (table->times_must_eat != -1)
        philo->times_must_eat = table->times_must_eat;
    else
        philo->times_must_eat = 7;                          //<----------- Hard coded, change that
    philo->id = i;
    philo->status = 0;
    philo->full = FALSE;
    philo->times_eaten = 0;
    philo->left_fork = &table->forks[i];
    philo->right_fork = &table->forks[(i + 1) % table->number_philo];
    //philosophers[i]->print_mutex = &print_mutex;
    philo->time_to_die = table->time_to_die;
    philo->time_to_eat = table->time_to_eat;
    philo->time_to_sleep = table->time_to_sleep;
    philo->last_meal = table->start_time;                   //<----------  Not sure about this 
    pthread_create(&(philo->thread), NULL, say_hello, (void *)philo);
    return (philo);
}

/*
**  It initializes the table and set the philosophers to eat                    <-- We need one philo to control the table, stablish the routine to do so
**  Remember that its passed by reference -- good practice?
*/
void    ft_greet_philos(t_table **table)                            
{
    int i;
    pthread_t monitor;

    i = 0;
    while (i < (*table)->number_philo)
    {
        (*table)->philosophers[i] = ft_enter_philo(*table, i);
        i++;
    }
    pthread_create(&monitor, NULL, serve, (void *)*table);
}