#include "table.h"

void ft_print_fork_taken(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    if (ft_get_critical_end_dinner(philo->table) == FALSE)
        printf("%ld %d has taken a fork\n", ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}

void ft_print_eating(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    if (ft_get_critical_end_dinner(philo->table) == FALSE)
        printf("%ld %d is eating\n", ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}
void ft_print_sleeping(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    if (ft_get_critical_end_dinner(philo->table) == FALSE)
        printf("%ld %d is sleeping\n", ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}

void ft_print_thinking(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    if (ft_get_critical_end_dinner(philo->table) == FALSE)
        printf("%ld %d is thinking\n", ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}

void ft_print_dead(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    printf("%ld %d died\n", ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}