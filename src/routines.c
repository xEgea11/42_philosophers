#include "philosophers.h"
#include "table.h"

static int ft_waiting_for_philos(t_table *table)
{
    int i;

    i = 0;
    while (i < table->number_philo)
    {
        if (table->philosophers[i]->arrived == FALSE)   //<---- Maybe put a mutex here
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
        table->philosophers[i]->can_eat = TRUE;         //<---- Maybe put a mutex here
        printf("Philo %d can eat\n", table->philosophers[i]->id);
        i++;
    }
}

static int ft_philo_dead(t_table *table)
{
    int i;

    i = 0;
    while (i < table->number_philo)
    {
        if (table->philosophers[i]->dead == TRUE)
            return (TRUE);
        i++;
    }
    return (FALSE);
}

void ft_get_fork(t_philo *philo, int fork)
{
    if (fork == FIRST_FORK)
        pthread_mutex_lock(philo->first_fork);
    else if (fork == SECOND_FORK)
        pthread_mutex_lock(philo->second_fork);
    //gettimeofday(&(philo->current_time), NULL);
    ft_print_action(philo->current_time, philo->id, FORK_TAKEN);
}
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

int ft_everyone_ate(t_table *table)
{
    int i;
    i = 0;
    while (i < table->number_philo)
    {
        if (table->philosophers[i]->times_eaten != table->philosophers[i]->times_must_eat)
            return (FALSE);
        i++;
    }
    gettimeofday(&table->end_time, NULL);
    printf(RED "End time: %ld\n" RESET, ft_time_milis(table->end_time));
    return (TRUE);
}
//Routine for monitor                           <--- We need to do routine for monitor
void *serve(void *arg)
{
    t_table *table = (t_table *)arg;
    while (ft_waiting_for_philos(table) == FALSE)
        ;
    ft_start_dinner(table);
    while (!ft_everyone_ate(table))
    {
        if (ft_philo_dead(table) == TRUE)
        {
            printf(RED"Someone died, stop the simulation\n"RESET);
            return (NULL);
        }
    }
    //printf(RED"Everyone ate, bye i'm done here\n"RESET);
    return (NULL);
}