/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:38:06 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/29 12:38:07 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

int ft_parse_numbers(char **argv)
{
    int i;
    int number;

    i = 0;
    while (argv[i])
    {   
        number = ft_atol(argv[i]);
        if (number == -1)
            return (FALSE);
        if ((i == 2 || i == 3 || i == 4) && number < 60)
            return (FALSE);
        i++;
    }
    return (TRUE);
}

int ft_parse_args(int argc, char **argv)
{
    if (ft_check_argc(argc) == FALSE)
        return (FALSE);
    if (ft_parse_numbers(argv) == FALSE)
        return (FALSE);
    return (TRUE);
    
}

int ft_no_meals_condition(int argc, char *argv[])
{
    if (argc == 6 && ft_atol(argv[5]) == 0)
        return (TRUE);
    return (FALSE);
}
