#include "philosophers.h"

//We let this here provisionally; change for others functions
//to error handling
int	ft_atoi(const char *str)
{
	int		sign;
	int		value;
	size_t	idx;

	sign = 1;
	value = 0;
	idx = 0;
	while ((str[idx] >= '\t' && str[idx] <= '\r') || str[idx] == ' ')
		idx++;
	if (str[idx] == '-')
	{
		idx++;
		sign = -1;
	}
	else if (str[idx] == '+')
	{
		idx++;
		sign = 1;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		value = value * 10 + str[idx] - '0';
		idx++;
	}
	return (value *= sign);
}

//aux funct to check if number of arguments are valid
int ft_check_argc(int argc)
{
    if (argc != 5 && argc != 6)
    {
        printf("Error: wrong number of arguments\n");
        return (FALSE);
    }
    return (TRUE);
}

int ft_is_positive(int number)
{
    if (number < 0 || number == 0)
        return (FALSE);
    else
        return (TRUE);
}
/*
    Function to check if the numbers are valid
    1. check if the arguments are numbers
    2. check if the arguments are integers
    3. check if the arguments are positive
    4. check if the arguments are not 0
    5. check if the arguments fit in the range of int    
*/
int ft_check_numbers(char **argv)
{
    int i;
    int number;

    i = 0;
    while (argv[i])
    {
                                                        //<------------------  We let it provisionally for now
                                                        //<------------------  It need to check a bunch of things - define what
        number = ft_atoi(argv[i]);
        if (ft_is_positive(number) == FALSE)
            return (EXIT_FAILURE);
        i++;
    }
    return (TRUE);
}


int ft_check_args(int argc, char **argv)
{
    if (ft_check_argc(argc) == FALSE)
        return (FALSE);
    if (ft_check_numbers(argv) == FALSE)
        return (FALSE);
    return (TRUE);
    
}
