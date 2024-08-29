#include "table.h"

long ft_milis_to_micros(long milis)
{
    return (milis * 1000);
}

long ft_time_milis(struct timeval time, t_table *table)
{
    return (((time.tv_sec * 1000) + (time.tv_usec / 1000)) - ((table->start_time.tv_sec * 1000) + (table->start_time.tv_usec / 1000)));
}
