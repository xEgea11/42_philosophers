/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:38:11 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/29 12:38:12 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

int ft_is_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
        return (TRUE);
    return (FALSE);
}

int	ft_atol(const char *str)
{
	int		sign;
	int		value;
	size_t	idx;

	value = 0;
	idx = 0;
	while (ft_is_space(str[idx]))
		idx++;
	if (str[idx] == '-')
		return (-1);
	else if (str[idx] == '+')
		idx++;
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		value = value * 10 + str[idx] - '0';
		idx++;
	}
    if (value > 2147483647)
        return (-1);
	return (value);
}

int ft_check_argc(int argc)
{
    if (!(argc == 5 || argc == 6))
    {
        printf("Error\n");
        return (FALSE);
    }
    return (TRUE);
}