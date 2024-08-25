#include "philosophers.h"
#include "table.h"

void ft_print_fork_taken(struct timeval time, int id)
{
    gettimeofday(&(time), NULL);
    printf(BLUE "%ld %d, 🍴has taken a fork🍴\n" RESET, ft_time_milis(time), id);
}

void ft_print_eating(struct timeval time, int id)
{
    gettimeofday(&(time), NULL);
    printf(GREEN "%ld philo"YELLOW " %d"GREEN ", 🍔is eating🍔\n" RESET, ft_time_milis(time), id);
}
void ft_print_sleeping(struct timeval time, int id)
{
    gettimeofday(&(time), NULL);
    printf(VIOLET "%ld %d 😴is sleeping😴 \n" RESET, ft_time_milis(time), id);
}

void ft_print_thinking(struct timeval time, int id)
{
    gettimeofday(&(time), NULL);
    printf(YELLOW "%ld %d 🤔is thinking🤔\n" RESET, ft_time_milis(time), id);
}

void ft_print_dead(struct timeval time, int id)
{
    gettimeofday(&(time), NULL);
    printf(RED "%ld I'm philo %d, I DIED☠️\n" RESET, ft_time_milis(time), id);
}

void ft_print_arrived(struct timeval time, int id)
{
    gettimeofday(&(time), NULL);
    printf(GREEN "%ld %d arrived 🤟😬\n" RESET, ft_time_milis(time), id);
}

void ft_print_left(struct timeval time, int id)
{
    gettimeofday(&(time), NULL);
    printf(GREEN "%ld %d left✋😄\n" RESET, ft_time_milis(time), id);
}

void ft_print_action(struct timeval time, int id, int opcode)
{
    if (opcode == FORK_TAKEN)
        ft_print_fork_taken(time, id);
    else if (opcode == EATING)
        ft_print_eating(time, id);
    else if (opcode == SLEEPING)
        ft_print_sleeping(time, id);
    else if (opcode == THINKING)
        ft_print_thinking(time, id);
    else if (opcode == DEAD)
        ft_print_dead(time, id);
    else if (opcode == ARRIVED)
        ft_print_arrived(time, id);
    else if (opcode == LEFT)
        ft_print_left(time, id);
    else 
        printf("Bad opcode\n");
}

void ft_print_times_eaten(struct timeval current_time, int id, int times_eaten, int must_eat)
{
    gettimeofday(&(current_time), NULL);
    if (times_eaten == must_eat)
        printf(VIOLET "%ld philo" YELLOW" %d" VIOLET ", has finished!\n" RESET, ft_time_milis(current_time), id);
    else
        printf(VIOLET "%ld philo" YELLOW" %d" VIOLET ", has eaten " YELLOW "%d " VIOLET "times\n" RESET, ft_time_milis(current_time), id, times_eaten);
}
