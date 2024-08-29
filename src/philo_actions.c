/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:36:40 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/29 12:36:41 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

void ft_get_forks(t_philo *philo)
{
    if (philo->first_fork == philo->second_fork)
    {
        pthread_mutex_lock(philo->first_fork);
        ft_print_action(philo, philo->current_time, philo->id, FORK_TAKEN);
        while (ft_get_critical_end_dinner(philo->table) == FALSE)
            ;
    }
    else 
    {
        pthread_mutex_lock(philo->first_fork);
        ft_print_action(philo, philo->current_time, philo->id, FORK_TAKEN);
        pthread_mutex_lock(philo->second_fork);
        ft_print_action(philo, philo->current_time, philo->id, FORK_TAKEN);
    }
}

void ft_leave_forks(t_philo *philo)
{
        pthread_mutex_unlock(philo->first_fork);
        pthread_mutex_unlock(philo->second_fork);
}

void ft_eat(t_philo *philo)
{
    if (ft_get_critical_end_dinner(philo->table) == FALSE)
    {
        ft_get_forks(philo);
        ft_set_critical_last_meal(philo, TRUE);
        ft_print_action(philo, philo->current_time, philo->id, EATING);
        philo->times_eaten++;
        usleep(ft_milis_to_micros(philo->table->time_to_eat));
        ft_leave_forks(philo);
    }
}

void ft_sleep(t_philo *philo)
{
    if (ft_get_critical_end_dinner(philo->table) == FALSE)
    {
        ft_print_action(philo, philo->current_time, philo->id, SLEEPING);
        usleep(ft_milis_to_micros(philo->table->time_to_sleep));
    }
}

void ft_think(t_philo *philo)
{
    if (ft_get_critical_end_dinner(philo->table) == FALSE)
    {
        if (philo->table->time_to_eat >= philo->table->time_to_sleep)
            usleep(ft_milis_to_micros(philo->table->time_to_eat) - ft_milis_to_micros(philo->table->time_to_sleep) + 1000);
        ft_print_action(philo, philo->current_time, philo->id, THINKING);
    }
}