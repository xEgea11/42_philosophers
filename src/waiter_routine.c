#include "table.h"

static int ft_waiting_for_philos(t_table *table)
{
    int i;
    int value;

    i = 0;
    value = 0;
    while (i < table->number_philo)
    {
        pthread_mutex_lock(&table->philosophers[i]->arrived_mutex);
        value = table->philosophers[i]->arrived;
        pthread_mutex_unlock(&table->philosophers[i]->arrived_mutex);
        if (value == FALSE)
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
        pthread_mutex_lock(&table->philosophers[i]->can_eat_mutex);
        table->philosophers[i]->can_eat = TRUE;         
        pthread_mutex_unlock(&table->philosophers[i]->can_eat_mutex);
        i++;
    }
}

static int ft_check_death(t_table *table)
{
    int i;
    long last_meal;

    i = 0;
    while (i < table->number_philo)
    {
        pthread_mutex_lock(&table->philosophers[i]->last_meal_mutex);
        last_meal = ft_time_milis(table->philosophers[i]->last_meal, table);
        pthread_mutex_unlock(&table->philosophers[i]->last_meal_mutex);
        gettimeofday(&table->current_time, NULL);
        if (ft_time_milis(table->current_time, table) - last_meal > table->time_to_die)
        {
            pthread_mutex_lock(&table->end_simulation_mutex);
            table->end_simulation = TRUE;
            pthread_mutex_unlock(&table->end_simulation_mutex);
            ft_print_action(table->philosophers[i], table->end_time, table->philosophers[i]->id, DEAD);
            return (TRUE);
        }
        i++;
    }
    return (FALSE);
}

static int ft_everyone_ate(t_table *table)
{
    int i;
    int value;

    i = 0;
    value = 0;
    while (i < table->number_philo)
    {
        pthread_mutex_lock(&table->philosophers[i]->full_mutex);
        value = table->philosophers[i]->full;
        pthread_mutex_unlock(&table->philosophers[i]->full_mutex);
        if (value == FALSE)
            return (FALSE);
        i++;
    }
    return (TRUE);
}

void *serve(void *arg)
{
    t_table *table = (t_table *)arg;
    while (ft_waiting_for_philos(table) == FALSE)
        ;
    ft_start_dinner(table);             //Either set a flag on philos or a flag on the table, what is best?
    while (!ft_everyone_ate(table))
    {
        if (ft_check_death(table) == TRUE)
        {
            printf(RED " 🚨 CALL THE AMBULANCE!! 🚨\n" RESET);
            return (NULL);
        }
    }
    pthread_mutex_lock(&table->end_simulation_mutex);
    table->end_simulation = TRUE;
    pthread_mutex_unlock(&table->end_simulation_mutex);
    return (NULL);
}