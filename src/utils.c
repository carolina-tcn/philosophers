/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:25:14 by ctacconi          #+#    #+#             */
/*   Updated: 2024/08/03 14:22:17 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//function that compares the two strings s1 and s2, returns an int
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0' || s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}
//int	usleep(useconds_t usec)-> suspends execution of the calling thread
//for (at least) usec microseconds
void	ft_usleep(long milliseconds)
{
	long	start;

	start = get_time_ms();
	while (1)
	{
		if ((get_time_ms() - start) >= milliseconds)
			break;
		usleep(100);
	}
}
//Function that calculate time in miliseconds
//La función get_time_ms en C tiene como objetivo obtener el tiempo actual en milisegundos desde la época (Epoch), que es el punto de referencia temporal estándar en Unix (1 de enero de 1970, 00:00:00 UTC).
//Function that obtains the milliseconds elapsed since 1970-01-01
long	get_time_ms(void)
{
	struct timeval	time_value;
	long			current_time;

	gettimeofday(&time_value, NULL);
	current_time = 	(time_value.tv_sec * 1000L) + (time_value.tv_usec / 1000L);
	return (current_time);
}