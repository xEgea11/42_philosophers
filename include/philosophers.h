#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>


# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define TRUE 1
# define FALSE 0



//OPCODES
# define THINKING 0
# define SLEEPING 1
# define EATING 2
# define DEAD 3
# define ARRIVED 4
# define LEFT 5

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
    //0 for alive, 1 for dead
    int status;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    //pthread_mutex_t *print_mutex;
    int times_eaten;
    int times_must_eat;
    struct timeval last_meal;
    //current time; remove later maybe
    struct timeval current_time;
    struct timeval start;
    struct timeval end;

    long time_to_die;
    long time_to_eat;
    long time_to_sleep;

    pthread_t thread;
}   t_philo;

typedef struct s_data
{
    struct timeval start_time;
    struct timeval end_time;
    int number_philo;
    int times_must_eat;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    t_philo **philosophers;
    pthread_mutex_t *forks;
}   t_table;


//Arg_check functions
//provisionally
int	ft_atoi(const char *str);
int ft_check_argc(int argc);
int ft_is_positive(int number);
int ft_check_numbers(char **argv);
int ft_check_args(int argc, char **argv);

//Table functions
t_table *ft_set_table(int argc, char *argv[]);
void ft_clean_table(t_table *table);

//greeting and saying goodbye to philos
t_philo *ft_enter_philo(t_table *table, int i);
void    ft_greet_philos(t_table **table);

//Routine functions
void *say_hello(void *arg);
void *monitor(void *arg);

//Print functions
void ft_print_action(struct timeval time, int id, int opcode);
void ft_print_times_eaten(struct timeval current_time, int id, int times_eaten, int must_eat);


//Utils functions
long ft_time_milis(struct timeval time);

#endif