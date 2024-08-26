#include "philosophers.h"
#include "table.h"

void ft_print_fork_taken(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    printf(BLUE "%ld %d has taken a fork\n" RESET, ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}

void ft_print_eating(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    printf(GREEN "%ld %d"GREEN " is eating\n" RESET, ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}
void ft_print_sleeping(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    printf(VIOLET "%ld %d is sleeping \n" RESET, ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}

void ft_print_thinking(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    printf(YELLOW "%ld %d is thinking\n" RESET, ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}

void ft_print_dead(t_philo *philo, struct timeval time, int id)
{
    pthread_mutex_lock(&philo->table->print_mutex);
    gettimeofday(&(time), NULL);
    printf(RED "%ld %d died,\n" RESET, ft_time_milis(time, philo->table), id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}
/* NOT NEEDED */
//void ft_print_arrived(t_philo *philo, struct timeval time, int id)
//{
//    pthread_mutex_lock(&philo->table->print_mutex);
//    gettimeofday(&(time), NULL);
//    printf(GREEN "%ld %d arrived 🤟😬\n" RESET, ft_time_milis(time, philo->table), id);
//    pthread_mutex_unlock(&philo->table->print_mutex);
//}
//
//void ft_print_left(t_philo *philo, struct timeval time, int id)
//{
//    pthread_mutex_lock(&philo->table->print_mutex);
//    gettimeofday(&(time), NULL);
//    printf(GREEN "%ld %d left✋😄\n" RESET, ft_time_milis(time, philo->table), id);
//    pthread_mutex_unlock(&philo->table->print_mutex);
//}

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
    //else if (opcode == ARRIVED)
    //    ft_print_arrived(philo, time, id);
    //else if (opcode == LEFT)
    //    ft_print_left(philo, time, id);
    else 
        printf("Bad opcode\n");
}