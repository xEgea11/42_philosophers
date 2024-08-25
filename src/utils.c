#include "philosophers.h"
#include "table.h"

//Calculate time in milliseconds
long ft_time_milis(struct timeval time, t_table *table)
{
    return (time.tv_sec * 1000 + time.tv_usec / 1000 - table->start_time.tv_sec * 1000 - table->start_time.tv_usec / 1000);
}