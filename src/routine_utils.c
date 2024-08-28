#include "table.h"

int ft_check_critical_end_dinner(t_table *table)
{
    int value;

    pthread_mutex_lock(&table->end_simulation_mutex);
    value = table->end_simulation;
    pthread_mutex_unlock(&table->end_simulation_mutex);

    return (value);
}

void ft_set_critical_arrived(t_philo *philo, int value)
{
    pthread_mutex_lock(&philo->arrived_mutex);
    philo->arrived = value;
    pthread_mutex_unlock(&philo->arrived_mutex);
}

int ft_get_critical_can_eat(t_philo *philo)
{
    int value;

    pthread_mutex_lock(&philo->can_eat_mutex);
    value = philo->can_eat;
    pthread_mutex_unlock(&philo->can_eat_mutex);

    return (value);
}

void ft_set_critical_full(t_philo *philo, int value)
{
    if (philo->table->nbr_meals == TRUE && philo->times_eaten == philo->table->times_must_eat)
    {
        pthread_mutex_lock(&philo->full_mutex);
        philo->full = value;
        pthread_mutex_unlock(&philo->full_mutex);
    }
}