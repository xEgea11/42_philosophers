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
# define LEFT 4
# define ARRIVED 5

# define FIRST_FORK 0
# define SECOND_FORK 1

# define FORK_TAKEN 6
# define FORK_FREE 7

# define READ 1
# define WRITE 0

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
int ft_one_philo(char *argv[]);

//Routine functions
void *say_hello(void *arg);
void *serve(void *arg);

//Print functions
void ft_print_action(t_philo *philo, struct timeval time, int id, int opcode);

//Utils functions
long ft_time_milis(struct timeval time, t_table *table);
long ft_milis_to_micros(long milis);

#endif