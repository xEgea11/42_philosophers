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
# define ARRIVED 5
# define LEFT 6

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

typedef struct s_philo
{
    int id;
    int dead;
    int full;
    //For synchronization purposes
    int arrived;
    int can_eat;
    pthread_mutex_t *first_fork;
    pthread_mutex_t *second_fork;
    //pthread_mutex_t *print_mutex;
    int times_eaten;
    struct timeval last_meal;
    struct timeval current_time;
    struct timeval start;
    struct timeval end;

    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    int  times_must_eat;

    pthread_t thread;
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
void ft_print_action(struct timeval time, int id, int opcode);
void ft_print_times_eaten(struct timeval current_time, int id, int times_eaten, int must_eat);


//Utils functions
long ft_time_milis(struct timeval time);

#endif