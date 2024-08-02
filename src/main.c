/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:33:16 by ctacconi          #+#    #+#             */
/*   Updated: 2024/08/02 19:13:14 by ctacconi         ###   ########.fr       */
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
	init(&table, argv);
	create_threads(&table);
	monitoring(&table);
	join_threads(&table);
	//while join de los hilos. join is going to pause and wait here until this thread
	ft_clean(&table);
	return (EXIT_SUCCESS);
}
