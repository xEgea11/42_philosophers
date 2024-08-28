#include "philosophers.h"
#include "table.h"

/*
    Fake to lock the fork
    Sleep until the monitor will bust it
*/
//void *ft_one_philo(void *arg)
//{
//    t_philo *philo;
//
//    philo = (t_philo *)arg;
//}

static void ft_get_forks(t_philo *philo)
{
    pthread_mutex_lock(philo->first_fork);
    ft_print_action(philo, philo->current_time, philo->id, FORK_TAKEN);
    pthread_mutex_lock(philo->second_fork);
    ft_print_action(philo, philo->current_time, philo->id, FORK_TAKEN);
}

static void ft_leave_forks(t_philo *philo)
{
    pthread_mutex_unlock(philo->first_fork);
    pthread_mutex_unlock(philo->second_fork);
}

void ft_eat(t_philo *philo)
{
    if (ft_check_critical_end_dinner(philo->table) == FALSE)
    {
        ft_get_forks(philo);
        pthread_mutex_lock(&philo->last_meal_mutex);
        gettimeofday(&(philo->last_meal), NULL);
        pthread_mutex_unlock(&philo->last_meal_mutex);
        ft_print_action(philo, philo->current_time, philo->id, EATING);
        philo->times_eaten++;
        usleep(ft_milis_to_micros(philo->table->time_to_eat));
        ft_leave_forks(philo);
    }
}

static void ft_sleep(t_philo *philo)
{
    if (ft_check_critical_end_dinner(philo->table) == FALSE)
    {
        ft_print_action(philo, philo->current_time, philo->id, SLEEPING);
        usleep(ft_milis_to_micros(philo->table->time_to_sleep));
    }
}

static void ft_think(t_philo *philo)
{
    if (ft_check_critical_end_dinner(philo->table) == FALSE)
    ft_print_action(philo, philo->current_time, philo->id, THINKING);
}

void *say_hello(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;

    ft_set_critical_arrived(philo, TRUE);
    while (ft_get_critical_can_eat(philo) == FALSE)
        ;
    while (ft_check_critical_end_dinner(philo->table) == FALSE)
    {
        ft_eat(philo);
        ft_set_critical_full(philo, TRUE);
        ft_sleep(philo);
        ft_think(philo);
    }
    return (NULL);
}

