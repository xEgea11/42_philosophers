/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:38:22 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/29 16:03:46 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H

# define TABLE_H
# include "philosophers.h"

typedef struct s_philo t_philo; //forwarded declaration

typedef struct s_data
{
    int end_simulation;
    pthread_mutex_t end_simulation_mutex;

    struct timeval start_time;
    struct timeval end_time;
    struct timeval current_time;

    size_t number_philo;
    pthread_mutex_t *forks;
    
    t_philo **philosophers;
    pthread_t monitor;

    int nbr_meals;
    int times_must_eat;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;

    pthread_mutex_t print_mutex;
}   t_table;


void ft_init_mutexes(t_table *table);
void ft_assign_forks(t_table *table, t_philo *philo, int id);
t_philo *ft_data_init_philo(t_table *table, int id);
t_philo *ft_enter_philo(t_table *table, int i);
void    ft_greet_philos(t_table *table);

t_table *ft_set_table(int argc, char *argv[]);
void    ft_finish_dinner(t_table *table);
void    ft_clean_table(t_table *table);

#endif