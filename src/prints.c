#include "table.h"

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
    else 
        printf("Bad opcode\n");
}