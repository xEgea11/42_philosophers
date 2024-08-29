#ifndef TABLE_H

# define TABLE_H
# include "philosophers.h"

typedef struct s_philo t_philo; //forwarded declaration

typedef struct s_data
{
    int end_simulation;                         //<<----- Monitor sets to one if someone dead; philos check if they can do action
    pthread_mutex_t end_simulation_mutex;

    int all_philos_ready;           // <---- Not sure if I'll use this one or the one onto the philo struct

    struct timeval start_time;  //<--- All philos should start with this time
    struct timeval end_time;       //<--- A philo dies or everyone has eaten
    struct timeval current_time; //<--- Current time for the monitor, no need for mutex 

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

int ft_table_for_one(t_table *table);

t_table *ft_set_table(int argc, char *argv[]);
void    ft_finish_dinner(t_table *table);
void    ft_clean_table(t_table *table);

#endif