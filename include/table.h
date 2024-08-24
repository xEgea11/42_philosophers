#ifndef TABLE_H

# define TABLE_H
# include "philosophers.h"

typedef struct s_philo t_philo; //forwarded declaration

typedef struct s_data
{
    int end_simulation;
    struct timeval start_time;  //<--- All philos should start with this time
    struct timeval end_time;       //<--- A philo dies or everyone has eaten 
    size_t number_philo;
    size_t times_must_eat;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    t_philo **philosophers;
    pthread_mutex_t *forks;
}   t_table;


//Table functions
t_table *ft_set_table(int argc, char *argv[]);
void ft_clean_table(t_table *table);

//greeting and saying goodbye to philos
t_philo *ft_enter_philo(t_table *table, int i);
void    ft_greet_philos(t_table **table);



#endif