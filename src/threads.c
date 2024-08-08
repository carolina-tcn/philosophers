/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:11:08 by ctacconi          #+#    #+#             */
/*   Updated: 2024/08/07 13:29:54 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//Function that creats a thread per philosopher
int	create_threads(t_table *table)
{
	int			i;

	i = 0;
	pthread_mutex_lock(&table->start_lock);
	while (i < table->number_of_philosophers)
	{
		if (pthread_create(&(table->philos[i].thread), NULL, &philo_routine,
				(void *)&(table->philos[i])) == -1)
		{
			pthread_mutex_unlock(&table->start_lock);
			return (0);
		}
		i++;
	}
	table->start_time = get_time_ms();
	i = 0;
	while (i < table->number_of_philosophers)
	{
		table->philos[i].last_meal = table->start_time;
		i++;
	}
	pthread_mutex_unlock(&table->start_lock);
	return (1);
}

void	join_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
}
