#include "philosophers.h"


//Routine for philosophers
void *say_hello(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    //Hardcoded times of eating
    gettimeofday(&(philo->start), NULL);
    ft_print_action(philo->start, philo->id, ARRIVED);
    //Hardcoded; We need to change this to make it more accurate
    printf("Waiting for others\n");
    usleep(100);
    while (philo->times_eaten < philo->times_must_eat)
    {
        gettimeofday(&(philo->current_time), NULL);
        //This is why we cannot calculate if a thread is dead; once calculated diffs between times, a thread just waits 
        if (philo->time_to_die < (ft_time_milis(philo->current_time) - ft_time_milis(philo->last_meal)))
        {
            ft_print_action(philo->current_time, philo->id, DEAD);
            philo->status = 1;
            return (NULL);
        }

        if (philo->time_to_sleep > (ft_time_milis(philo->current_time) - ft_time_milis(philo->last_meal)))
        {
            usleep(philo->time_to_sleep);
            gettimeofday(&(philo->current_time), NULL);
            ft_print_action(philo->current_time, philo->id, SLEEPING);
        }
        gettimeofday(&(philo->current_time), NULL);
        ft_print_action(philo->current_time, philo->id, THINKING);
        pthread_mutex_lock(philo->left_fork);
        gettimeofday(&(philo->current_time), NULL);
        ft_print_action(philo->current_time, philo->id, FORK_TAKEN);
        pthread_mutex_lock(philo->right_fork);
        gettimeofday(&(philo->current_time), NULL);
        ft_print_action(philo->current_time, philo->id, FORK_TAKEN);
        ft_print_action(philo->current_time, philo->id, EATING);
        gettimeofday(&(philo->start), NULL);
        gettimeofday(&(philo->current_time), NULL);
        while (philo->time_to_eat > (ft_time_milis(philo->current_time) - ft_time_milis(philo->start)))
            gettimeofday(&(philo->current_time), NULL);
        gettimeofday(&(philo->last_meal), NULL);
        philo->times_eaten++;
        //pthread_mutex_lock(philo->print_mutex);
        ft_print_times_eaten(philo->current_time, philo->id, philo->times_eaten, philo->times_must_eat);
        //pthread_mutex_unlock(philo->print_mutex);
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
    }
    gettimeofday(&(philo->end), NULL);
    ft_print_action(philo->end, philo->id, LEFT);
    return (NULL);
}

//Routine for monitor                           <--- We need to do routine for monitor
void *monitor(void *arg)
{
    printf("Hello");
}