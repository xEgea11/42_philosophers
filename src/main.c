/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:18:52 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/25 16:03:06 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "table.h"

//./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]

int main(int argc, char *argv[])
{
    t_table *table;
    if (ft_parse_args(argc, argv) == FALSE)
    {
        printf("Arguments are not valid\n");
        return (EXIT_FAILURE);
    }
    if (ft_no_meals_condition(argc, argv) == TRUE)
        return (EXIT_SUCCESS);

    if (ft_one_philo(argv) == TRUE)
    {
        printf("Only one philosopher\n");       //<--- Ad hoc function for one philosopher
        return (EXIT_SUCCESS);
    }
    table = ft_set_table(argc, argv);
    ft_greet_philos(table);
    ft_finish_dinner(table);
    ft_clean_table(table);

    return (EXIT_SUCCESS);
}