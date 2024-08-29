#include "table.h"

void ft_print_fork_taken(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    if (ft_get_critical_end_dinner(philo->table) == FALSE)
        printf(BLUE "%ld %d has taken a fork\n" RESET, ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}

void ft_print_eating(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    if (ft_get_critical_end_dinner(philo->table) == FALSE)
        printf(GREEN "%ld %d"GREEN " is eating\n" RESET, ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}
void ft_print_sleeping(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    if (ft_get_critical_end_dinner(philo->table) == FALSE)
        printf(VIOLET "%ld %d is sleeping\n" RESET, ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}

void ft_print_thinking(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    if (ft_get_critical_end_dinner(philo->table) == FALSE)
        printf(YELLOW "%ld %d is thinking\n" RESET, ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}

void ft_print_dead(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    printf(RED "%ld %d died\n" RESET, ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}