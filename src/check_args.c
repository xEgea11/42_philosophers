#include "philosophers.h"

int ft_is_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
        return (TRUE);
    return (FALSE);
}
//We let this here provisionally; change for others functions
//to error handling
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

//aux funct to check if number of arguments are valid
int ft_check_argc(int argc)
{
    if (!(argc == 5 || argc == 6))
    {
        printf("Error: wrong number of arguments\n");
        return (FALSE);
    }
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
int ft_parse_input(char **argv)
{
    int i;
    int number;

    i = 0;
    while (argv[i])
    {   
        number = ft_atol(argv[i]);           // <--- It puts to a long just check, but it has to be a positive int
        if (number == -1)
            return (FALSE);
        if ((i == 2 || i == 3 || i == 4) && number < 60)
            return (FALSE);
        i++;
    }
    return (TRUE);
}


int ft_check_args(int argc, char **argv)
{
    if (ft_check_argc(argc) == FALSE)
        return (FALSE);
    if (ft_parse_input(argv) == FALSE)
        return (FALSE);
    return (TRUE);
    
}
