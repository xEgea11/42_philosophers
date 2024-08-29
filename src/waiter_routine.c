/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:36:51 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/29 12:36:52 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

void *serve(void *arg)
{
    t_table *table;

    table = (t_table *)arg;
    while (ft_waiting_for_philos(table) == FALSE)
        ;
    ft_start_dinner(table);
    while (!ft_everyone_ate(table))
    {
        if (ft_check_death(table) == TRUE)
            return (NULL);
    }
    ft_set_critical_end_dinner(table, TRUE);
    return (NULL);
}