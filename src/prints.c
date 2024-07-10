#include "philosophers.h"

void ft_print_action(struct timeval time, int id, int opcode)
{
    if (opcode == FORK_TAKEN)
        printf(BLUE "%ld %d, has taken a fork\n" RESET, ft_time_milis(time), id);
    else if (opcode == EATING)
        printf(GREEN "%ld philo"YELLOW " %d"GREEN ", is eating\n" RESET, ft_time_milis(time), id);
    else if (opcode == SLEEPING)
        printf(VIOLET "%ld %d is sleeping \n" RESET, ft_time_milis(time), id);
    else if (opcode == THINKING)
        printf(YELLOW "%ld %d is thinking\n" RESET, ft_time_milis(time), id);
    else if (opcode == DEAD)
        printf(RED "%ld I'm philo %d, I DIED\n" RESET, ft_time_milis(time), id);
    else if (opcode == ARRIVED)
        printf(GREEN "%ld %d arrived :D\n" RESET, ft_time_milis(time), id);
    else if (opcode == LEFT)
        printf(GREEN "%ld %d left\n" RESET, ft_time_milis(time), id);
    else 
        printf("Bad opcode\n");
}

void ft_print_times_eaten(struct timeval current_time, int id, int times_eaten, int must_eat)
{
    if (times_eaten == must_eat)
        printf(VIOLET "%ld philo" YELLOW" %d" VIOLET ", has finished!\n" RESET, ft_time_milis(current_time), id);
    else
        printf(VIOLET "%ld philo" YELLOW" %d" VIOLET ", has eaten " YELLOW "%d " VIOLET "times\n" RESET, ft_time_milis(current_time), id, times_eaten);
}
