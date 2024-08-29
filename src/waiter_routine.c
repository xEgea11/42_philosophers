#include "table.h"

void *serve(void *arg)
{
    t_table *table;

    table = (t_table *)arg;
    while (ft_waiting_for_philos(table) == FALSE)
        ;
    ft_start_dinner(table);             //Either set a flag on philos or a flag on the table, what is best?
    while (!ft_everyone_ate(table))
    {
        if (ft_check_death(table) == TRUE)
            return (NULL);
    }
    ft_set_critical_end_dinner(table, TRUE);
    return (NULL);
}