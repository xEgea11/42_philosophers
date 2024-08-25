#include "philosophers.h"
#include "table.h"

void ft_print_fork_taken(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    printf(BLUE "%ld %d, 🍴has taken a fork🍴\n" RESET, ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}

void ft_print_eating(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    printf(GREEN "%ld philo"YELLOW " %d"GREEN ", 🍔is eating🍔\n" RESET, ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}
void ft_print_sleeping(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    printf(VIOLET "%ld %d 😴is sleeping😴 \n" RESET, ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}

void ft_print_thinking(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    printf(YELLOW "%ld %d 🤔is thinking🤔\n" RESET, ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}

void ft_print_dead(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    printf(RED "%ld I'm philo %d, I DIED☠️\n" RESET, ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}

void ft_print_arrived(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    printf(GREEN "%ld %d arrived 🤟😬\n" RESET, ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}

void ft_print_left(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    printf(GREEN "%ld %d left✋😄\n" RESET, ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}

void ft_print_action(t_philo *philo, struct timeval time, int id, int opcode)
{
    if (opcode == FORK_TAKEN)
        ft_print_fork_taken(philo, time, id);
    else if (opcode == EATING)
        ft_print_eating(philo, time, id);
    else if (opcode == SLEEPING)
        ft_print_sleeping(philo, time, id);
    else if (opcode == THINKING)
        ft_print_thinking(philo, time, id);
    else if (opcode == DEAD)
        ft_print_dead(philo, time, id);
    else if (opcode == ARRIVED)
        ft_print_arrived(philo, time, id);
    else if (opcode == LEFT)
        ft_print_left(philo, time, id);
    else 
        printf("Bad opcode\n");
}

void ft_print_times_eaten(struct timeval current_time, int id, int times_eaten, int must_eat, t_table *table)
{
    gettimeofday(&(current_time), NULL);
    if (times_eaten == must_eat)
        printf(VIOLET "%ld philo" YELLOW" %d" VIOLET ", has finished!\n" RESET, ft_time_milis(current_time, table), id);
    else
        printf(VIOLET "%ld philo" YELLOW" %d" VIOLET ", has eaten " YELLOW "%d " VIOLET "times\n" RESET, ft_time_milis(current_time, table), id, times_eaten);
}
