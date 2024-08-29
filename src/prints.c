/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:37:16 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/29 12:37:17 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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