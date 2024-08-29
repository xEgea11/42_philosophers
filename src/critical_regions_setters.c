#include "table.h"

void ft_set_critical_end_dinner(t_table *table, int value)
{
    pthread_mutex_lock(&table->end_simulation_mutex);
    table->end_simulation = value;
    pthread_mutex_unlock(&table->end_simulation_mutex);
}

void ft_set_critical_arrived(t_philo *philo, int value)
{
    pthread_mutex_lock(&philo->arrived_mutex);
    philo->arrived = value;
    pthread_mutex_unlock(&philo->arrived_mutex);
}

void ft_set_critical_can_eat(t_philo *philo, int value)
{
    pthread_mutex_lock(&philo->can_eat_mutex);
    philo->can_eat = value;
    pthread_mutex_unlock(&philo->can_eat_mutex);
}

void ft_set_critical_full(t_philo *philo, int value)
{
    pthread_mutex_lock(&philo->full_mutex);
    philo->full = value;
    pthread_mutex_unlock(&philo->full_mutex);
}

void ft_set_critical_last_meal(t_philo *philo, int value)
{
    pthread_mutex_lock(&philo->last_meal_mutex);
    gettimeofday(&(philo->last_meal), NULL);
    pthread_mutex_unlock(&philo->last_meal_mutex);
}
