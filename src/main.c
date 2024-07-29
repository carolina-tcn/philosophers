/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:33:16 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/29 20:37:07 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//ARREGLAR MAKEFILE
//RACE CONDITION can happen when 2 or more threads are trying to access and modify the same variable at the same time
//int	usleep(useconds_t usec)-> suspends execution of the calling thread
//for (at least) usec microseconds
//initialize and destroy the mutex, and you have to do that every time you want to use a mutex (destroy it after you finished using it)

//Function that calculate time in miliseconds
long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L));
}

/*void	write()
{
	pthread_mutex_lock(write_lock);
	//escribir  el mensaje
	pthread_mutex_unlock(write_lock);	
}*/

int	main(int argc, char **argv)
{
	t_program	table;

	if (argc < 5 || argc > 6)
		return (error_message(INVALID_NUM_INPUT, EXIT_FAILURE));
	if (!check_args(argc, argv))
		return (error_message(INVALID_INPUT, EXIT_FAILURE));	
	//INICIALIZAR LOS DATOS (incluido philos)
	init(&table, argc, argv);
	//crear hilos x cada filo
	if (!create_threads(&table))
		//return error y liberarrr???
	//pthread_create()
	//llamar a funcion monitor que controla estado de philos
	//monitor();
	//while join de los hilos
	//clear_philos
	return (EXIT_SUCCESS);
}