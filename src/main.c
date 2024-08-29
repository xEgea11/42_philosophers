/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:18:52 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/29 12:37:24 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

int main(int argc, char *argv[])
{
    t_table *table;
    if (ft_parse_args(argc, argv) == FALSE)
    {
        printf("Error\n");
        return (EXIT_FAILURE);
    }
    if (ft_no_meals_condition(argc, argv) == TRUE)
        return (EXIT_SUCCESS);
    table = ft_set_table(argc, argv);
    ft_greet_philos(table);
    ft_finish_dinner(table);
    ft_clean_table(table);

    return (EXIT_SUCCESS);
}