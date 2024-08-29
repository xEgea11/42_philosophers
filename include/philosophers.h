/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:38:17 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/29 12:38:18 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include "table.h"

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define TRUE 1
# define FALSE 0

//OPCODES
# define THINKING 0
# define SLEEPING 1
# define EATING 2
# define DEAD 3

# define FIRST_FORK 0
# define SECOND_FORK 1

# define FORK_TAKEN 6
# define FORK_FREE 7

# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define RED "\033[0;31m"
# define VIOLET "\033[0;35m"
# define YELLOW "\033[0;33m"
# define RESET "\033[0m"

typedef struct s_data t_table;

typedef struct s_philo
{
    int id;
    int full;
    //For synchronization purposes
    int arrived;
    int can_eat;
    pthread_mutex_t full_mutex;
    pthread_mutex_t arrived_mutex;
    pthread_mutex_t can_eat_mutex;

    pthread_mutex_t *first_fork;
    pthread_mutex_t *second_fork;
    //
    int times_eaten;
    pthread_mutex_t last_meal_mutex;
    struct timeval last_meal;
    struct timeval current_time;
    struct timeval start;
    struct timeval end;

    t_table *table;
    pthread_t philo;
    
}   t_philo;

//Arg_check functions
// utility functions
int ft_is_space(char c);
int	ft_atol(const char *str);
int ft_check_argc(int argc);

int ft_parse_args(int argc, char **argv);
int ft_parse_numbers(char **argv);
int ft_no_meals_condition(int argc, char *argv[]);


//Routine utils functions
int ft_get_critical_end_dinner(t_table *table);
void ft_set_critical_end_dinner(t_table *table, int value);

int ft_get_critical_arrived(t_philo *philo);
void ft_set_critical_arrived(t_philo *philo, int value);

int ft_get_critical_can_eat(t_philo *philo);
void ft_set_critical_can_eat(t_philo *philo, int value);

int ft_get_critical_full(t_philo *philo);
void ft_set_critical_full(t_philo *philo, int value);

int ft_get_critical_last_meal(t_philo *philo);
void ft_set_critical_last_meal(t_philo *philo, int value);

//Philo actions
void ft_get_forks(t_philo *philo);
void ft_leave_forks(t_philo *philo);
void ft_eat(t_philo *philo);
void ft_sleep(t_philo *philo);
void ft_think(t_philo *philo);

//Waiter actions
int ft_waiting_for_philos(t_table *table);
void ft_start_dinner(t_table *table);
int ft_check_death(t_table *table);
int ft_everyone_ate(t_table *table);


//Routine functions
void *say_hello(void *arg);
void *serve(void *arg);

//Print functions
void ft_print_action(t_philo *philo, struct timeval time, int id, int opcode);

//Utils functions
long ft_time_milis(struct timeval time, t_table *table);
long ft_milis_to_micros(long milis);

//Print functions
void ft_print_fork_taken(t_philo *philo, struct timeval time, int id);
void ft_print_eating(t_philo *philo, struct timeval time, int id);
void ft_print_sleeping(t_philo *philo, struct timeval time, int id);
void ft_print_thinking(t_philo *philo, struct timeval time, int id);
void ft_print_dead(t_philo *philo, struct timeval time, int id);

#endif