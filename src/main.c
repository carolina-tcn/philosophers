/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:33:16 by ctacconi          #+#    #+#             */
/*   Updated: 2024/08/01 18:44:08 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//ARREGLAR MAKEFILE
//RACE CONDITION can happen when 2 or more threads are trying to access and modify the same variable at the same time
//int	usleep(useconds_t usec)-> suspends execution of the calling thread
//for (at least) usec microseconds
//initialize and destroy the mutex, and you have to do that every time you want to use a mutex (destroy it after you finished using it)

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

	gettimeofday(&time_value, NULL);
	return ((time_value.tv_sec * 1000L) + (time_value.tv_usec / 1000L));
}
//PHILOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO CARPETA
int	main(int argc, char **argv)
{
	t_table	table;
	int	i;

	if (argc < 5 || argc > 6)
		return (error_message(INVALID_NUM_INPUT, EXIT_FAILURE));
	if (!check_args(argc, argv))
		return (error_message(INVALID_INPUT, EXIT_FAILURE));	
	init(&table, argv);
	//crear hilos x cada filo
	create_threads(&table);
		//return error y liberarrr???
	//pthread_create()
	//llamar a funcion monitor que controla estado de philos
	monitoring(&table);
	//while join de los hilos. join is going to pause and wait here until this thread
	i = 0;
	while (i < table.number_of_philosophers)
	{
		if (pthread_join(table.philos[i].thread, NULL) != 0)
            return (1); //Gestionar
		printf("cierro hilo %d\n", i);
		i++;
	}
	//has completed its work
	//destroy mutexxxxxx
	//clear_ft
	return (EXIT_SUCCESS);
}

/*
TODO
- OPTIMIZAR F(X) DE GET TIME
- LIMPIAR TODO, LIBERAR TODO 
*/