/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:33:16 by ctacconi          #+#    #+#             */
/*   Updated: 2024/08/07 13:47:47 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//Cleans at the end: destroy the mutex and free the malloc
void	ft_clean(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&table->dead_lock);
	pthread_mutex_destroy(&table->start_lock);
	pthread_mutex_destroy(&table->write_lock);
	while (i < table->number_of_philosophers)
	{
		pthread_mutex_destroy(&table->philos[i].r_fork);
		if (table->philos[i].l_fork)
			pthread_mutex_destroy(table->philos[i].l_fork);
		pthread_mutex_destroy(table->philos[i].write_lock);
		pthread_mutex_destroy(table->philos[i].dead_lock);
		pthread_mutex_destroy(table->philos[i].start_lock);
		pthread_mutex_destroy(&table->philos[i].meal_lock);
		pthread_mutex_destroy(&table->philos[i].meals_eaten_lock);
		i++;
	}
	free(table->philos);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5 || argc > 6)
		return (error_message(INVALID_NUM_INPUT, EXIT_FAILURE));
	if (!check_args(argc, argv))
		return (error_message(INVALID_INPUT, EXIT_FAILURE));
	if (!init(&table, argv))
		return (error_message(ALLOC_ERROR, EXIT_FAILURE));
	if (!create_threads(&table))
	{
		join_threads(&table);
		ft_clean(&table);
		return (error_message(THREADS_ERROR, EXIT_FAILURE));
	}
	monitoring(&table);
	join_threads(&table);
	ft_clean(&table);
	return (EXIT_SUCCESS);
}
