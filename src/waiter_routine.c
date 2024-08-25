#include "table.h"

static int ft_waiting_for_philos(t_table *table)
{
    int i;

    i = 0;
    while (i < table->number_philo)
    {
        if (table->philosophers[i]->arrived == FALSE)   //<---- Maybe put a mutex here
            return (FALSE);
        i++;
    }
    return (TRUE);
}

static void ft_start_dinner(t_table *table)
{
    int i;

    i = 0;
    while (i < table->number_philo)
    {
        table->philosophers[i]->can_eat = TRUE;         //<---- Maybe put a mutex here
        printf("Philo %d can eat\n", table->philosophers[i]->id);
        i++;
    }
}

static int ft_everyone_ate(t_table *table)
{
    int i;
    i = 0;
    while (i < table->number_philo)
    {
        if (table->philosophers[i]->full == FALSE)
            return (FALSE);
        i++;
    }
    gettimeofday(&table->end_time, NULL);
    printf(RED "End time: %ld\n" RESET, ft_time_milis(table->end_time, table));
    return (TRUE);
}

static int ft_philo_dead(t_table *table)
{
    int i;

    i = 0;
    while (i < table->number_philo)
    {
        if (table->philosophers[i]->dead == TRUE)
            return (TRUE);
        i++;
    }
    return (FALSE);
}

void *serve(void *arg)
{
    t_table *table = (t_table *)arg;
    while (ft_waiting_for_philos(table) == FALSE)
        ;
    ft_start_dinner(table);
    while (!ft_everyone_ate(table))
    {
        if (ft_philo_dead(table) == TRUE)
        {
            printf(RED"Someone died, stop the simulation\n"RESET);
            return (NULL);
        }
    }
    //printf(RED"Everyone ate, bye i'm done here\n"RESET);
    return (NULL);
}