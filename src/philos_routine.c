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


void ft_get_forks(t_philo *philo)
{
    pthread_mutex_lock(philo->first_fork);
    ft_print_action(philo, philo->current_time, philo->id, FORK_TAKEN);
    pthread_mutex_lock(philo->second_fork);
    ft_print_action(philo, philo->current_time, philo->id, FORK_TAKEN);
}

void ft_leave_forks(t_philo *philo)
{
    pthread_mutex_unlock(philo->first_fork);
    pthread_mutex_unlock(philo->second_fork);
}

//Routine for philosophers
void *say_hello(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;

    pthread_mutex_lock(&philo->arrived_mutex);
    philo->arrived = TRUE;
    pthread_mutex_unlock(&philo->arrived_mutex);
    while (philo->can_eat == FALSE)
        ;
    while (philo->full == FALSE)
    {
        ft_get_forks(philo);
        gettimeofday(&(philo->last_meal), NULL);
        ft_print_action(philo, philo->current_time, philo->id, EATING);
        philo->times_eaten++;
        usleep(ft_milis_to_micros(philo->table->time_to_eat));
        ft_leave_forks(philo);
        if (philo->table->nbr_meals == TRUE && philo->times_eaten == philo->table->times_must_eat)
        {
            ft_print_action(philo, philo->current_time, philo->id, LEFT);
            pthread_mutex_lock(&philo->full_mutex);
            philo->full = TRUE;
            pthread_mutex_unlock(&philo->full_mutex);
        }
        if (philo->full == FALSE)
        {
            ft_print_action(philo, philo->current_time, philo->id, SLEEPING);
            usleep(ft_milis_to_micros(philo->table->time_to_sleep));
            ft_print_action(philo, philo->current_time, philo->id, THINKING);
        }        
    }
    return (NULL);
}

