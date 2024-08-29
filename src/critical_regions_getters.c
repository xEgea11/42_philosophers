#include "table.h"

int ft_get_critical_end_dinner(t_table *table)
{
    int value;

    pthread_mutex_lock(&table->end_simulation_mutex);
    value = table->end_simulation;
    pthread_mutex_unlock(&table->end_simulation_mutex);

    return (value);
}

int ft_get_critical_arrived(t_philo *philo)
{
    int value;

    pthread_mutex_lock(&philo->arrived_mutex);
    value = philo->arrived;
    pthread_mutex_unlock(&philo->arrived_mutex);

    return (value);
}

int ft_get_critical_can_eat(t_philo *philo)
{
    int value;

    pthread_mutex_lock(&philo->can_eat_mutex);
    value = philo->can_eat;
    pthread_mutex_unlock(&philo->can_eat_mutex);

    return (value);
}

int ft_get_critical_full(t_philo *philo)
{
    int value;

    pthread_mutex_lock(&philo->full_mutex);
    value = philo->full;
    pthread_mutex_unlock(&philo->full_mutex);

    return (value);
}

int ft_get_critical_last_meal(t_philo *philo)
{
    int value;

    pthread_mutex_lock(&philo->last_meal_mutex);
    value = ft_time_milis(philo->last_meal, philo->table);
    pthread_mutex_unlock(&philo->last_meal_mutex);

    return (value);
}