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


void ft_get_fork(t_philo *philo, int fork)
{
    if (fork == FIRST_FORK)
        pthread_mutex_lock(philo->first_fork);
    else if (fork == SECOND_FORK)
        pthread_mutex_lock(philo->second_fork);
    ft_print_action(philo->current_time, philo->id, FORK_TAKEN);
}

//Routine for philosophers
void *say_hello(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    //Hardcoded times of eating
    gettimeofday(&(philo->start), NULL);
    philo->arrived = TRUE;
    ft_print_action(philo->start, philo->id, ARRIVED);                                                
    while (philo->can_eat == FALSE)
    {
        printf("%d is waiting for others\n", philo->id);
    }
    while (philo->full == FALSE)
    {
        gettimeofday(&(philo->current_time), NULL);
        //Not sure this works to check if the philo is dead
        if (philo->time_to_die < (ft_time_milis(philo->current_time) - ft_time_milis(philo->last_meal)))
        {
            ft_print_action(philo->current_time, philo->id, DEAD);
            philo->dead = TRUE;
            return (NULL);
        }
        ft_print_action(philo->current_time, philo->id, THINKING);
        ft_get_fork(philo, FIRST_FORK);
        ft_get_fork(philo, SECOND_FORK);
        ft_print_action(philo->current_time, philo->id, EATING);
        gettimeofday(&(philo->last_meal), NULL);
        philo->times_eaten++;
        //pthread_mutex_lock(philo->print_mutex);
        ft_print_times_eaten(philo->current_time, philo->id, philo->times_eaten, philo->times_must_eat);
        usleep(philo->time_to_eat);
        //pthread_mutex_unlock(philo->print_mutex);
        pthread_mutex_unlock(philo->first_fork);
        pthread_mutex_unlock(philo->second_fork);
        if (philo->times_eaten == philo->times_must_eat)
            philo->full = TRUE;
        if (philo->full == FALSE)
        {
            ft_print_action(philo->current_time, philo->id, SLEEPING);
            usleep(philo->time_to_sleep);
        }        
    }
    gettimeofday(&(philo->end), NULL);
    ft_print_action(philo->end, philo->id, LEFT);
    return (NULL);
}

