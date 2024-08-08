/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:25:14 by ctacconi          #+#    #+#             */
/*   Updated: 2024/08/07 11:37:59 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//Function that compares the two strings s1 and s2, returns an int
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

//Function that obtains the milliseconds elapsed since 1970-01-01
long	get_time_ms(void)
{
	struct timeval	time_value;
	long			current_time;

	gettimeofday(&time_value, NULL);
	current_time = (time_value.tv_sec * 1000L) + (time_value.tv_usec / 1000L);
	return (current_time);
}

//Prints timestamp in millisec with the status of the philosophers
void	write_action(t_philo *philo, char *str, long action_time)
{
	pthread_mutex_lock(philo->write_lock);
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 0 || !ft_strncmp(str, "is dead", 8))
		printf("%ld %d %s \n", action_time - *philo->start_time,
			philo->id, str);
	pthread_mutex_unlock(philo->dead_lock);
	pthread_mutex_unlock(philo->write_lock);
}
