#include "philosophers.h"
#include "table.h"

/*
    Fake to lock the fork
    Sleep until the monitor will bust it
*/
//void *ft_one_philo(void *arg)
//{
//    t_philo *philo;
//
//    philo = (t_philo *)arg;
//}

void *say_hello(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;

    ft_set_critical_arrived(philo, TRUE);
    while (ft_get_critical_can_eat(philo) == FALSE)
        ;
    while (ft_get_critical_end_dinner(philo->table) == FALSE)
    {
        ft_eat(philo);
        if (philo->table->nbr_meals == TRUE && philo->times_eaten == philo->table->times_must_eat)
            ft_set_critical_full(philo, TRUE);
        ft_sleep(philo);
        ft_think(philo);
    }
    return (NULL);
}

