/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_funcs_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:37:46 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/29 12:37:47 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

t_philo *ft_data_init_philo(t_table *table, int id)
{
    t_philo *philo;

    philo = malloc(sizeof(t_philo));

    philo->id = id;
    philo->arrived = FALSE;
    philo->can_eat = FALSE;
    philo->full = FALSE;
    philo->times_eaten = 0;
    philo->last_meal = table->start_time;                   //Mbe change it 
    philo->table = table;
    pthread_mutex_init(&philo->arrived_mutex, NULL);
    pthread_mutex_init(&philo->can_eat_mutex, NULL);
    pthread_mutex_init(&philo->full_mutex, NULL);
    pthread_mutex_init(&philo->last_meal_mutex, NULL);

    return (philo);
}

void ft_init_mutexes(t_table *table)
{
    int i;

    i = 0;
    while (i < table->number_philo)
    {
        pthread_mutex_init(&table->forks[i], NULL);
        i++;
    }
    pthread_mutex_init(&table->print_mutex, NULL);
    pthread_mutex_init(&table->end_simulation_mutex, NULL);
}


void ft_assign_forks(t_table *table, t_philo *philo, int id)
{
    if (id % 2 == 0)
    {
        philo->first_fork = &table->forks[id];
        philo->second_fork = &table->forks[(id + 1) % table->number_philo];
    }
    else
    {
        philo->first_fork = &table->forks[(id + 1) % table->number_philo];
        philo->second_fork = &table->forks[id];
    }
}

t_philo *ft_enter_philo(t_table *table, int id)      //<--- Refactor this one
{
    t_philo *philo;

    philo = ft_data_init_philo(table, id);
    ft_assign_forks(table, philo, id);
    pthread_create(&(philo->philo), NULL, say_hello, (void *)philo);
    return (philo);
}

void    ft_greet_philos(t_table *table)                            
{
    int i;

    gettimeofday(&(table)->start_time, NULL);
    i = 0;
    while (i < table->number_philo)
    {
        table->philosophers[i] = ft_enter_philo(table, i);
        i++;
    }
    gettimeofday(&table->start_time, NULL);
    table->current_time = table->start_time;
    pthread_create(&table->monitor, NULL, serve, (void *)table);
}