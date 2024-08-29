/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:36:59 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/29 12:37:00 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

int ft_waiting_for_philos(t_table *table)
{
    int i;
    int value;

    i = 0;
    value = 0;
    while (i < table->number_philo)
    {
        if (ft_get_critical_arrived(table->philosophers[i]) == FALSE)
            return (FALSE);
        i++;
    }
    return (TRUE);
}

void ft_start_dinner(t_table *table)
{
    int i;

    i = 0;
    gettimeofday(&table->start_time, NULL);
    while (i < table->number_philo)
    {   
        ft_set_critical_last_meal(table->philosophers[i], ft_time_milis(table->start_time, table));
        ft_set_critical_can_eat(table->philosophers[i], TRUE);
        i++;
    }
}

int ft_everyone_ate(t_table *table)
{
    int i;
    int value;

    i = 0;
    value = 0;
    while (i < table->number_philo)
    {
        if (ft_get_critical_full(table->philosophers[i]) == FALSE)
            return (FALSE);
        i++;
    }
    return (TRUE);
}

int ft_check_death(t_table *table)
{
    int i;
    long last_meal;

    i = 0;
    while (i < table->number_philo)
    {
        last_meal = ft_get_critical_last_meal(table->philosophers[i]);
        gettimeofday(&table->current_time, NULL);
        if (ft_time_milis(table->current_time, table) - last_meal > table->time_to_die)
        {
            ft_set_critical_end_dinner(table, TRUE);
            ft_print_action(table->philosophers[i], table->end_time, table->philosophers[i]->id, DEAD);
            return (TRUE);
        }
        i++;
    }
    return (FALSE);
}
