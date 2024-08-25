#include "philosophers.h"

int ft_parse_numbers(char **argv)
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
    {
        printf("No meals to eat\n");
        return (TRUE);
    }
    return (FALSE);
}

int ft_one_philo(char *argv[])
{
    if (ft_atol(argv[1]) == 1)
    {
        printf("Only one philosopher\n");           //<--- Ad hoc function for one philosopher
        return (TRUE);
    }
    return (FALSE);
}