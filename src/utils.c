#include "philosophers.h"

//Calculate time in milliseconds
long ft_time_milis(struct timeval time)
{
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}