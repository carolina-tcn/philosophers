/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:33:16 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/31 18:11:23 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//ARREGLAR MAKEFILE
//RACE CONDITION can happen when 2 or more threads are trying to access and modify the same variable at the same time
//int	usleep(useconds_t usec)-> suspends execution of the calling thread
//for (at least) usec microseconds
//initialize and destroy the mutex, and you have to do that every time you want to use a mutex (destroy it after you finished using it)

//Function that calculate time in miliseconds
//La función get_time_ms en C tiene como objetivo obtener el tiempo actual en milisegundos desde la época (Epoch), que es el punto de referencia temporal estándar en Unix (1 de enero de 1970, 00:00:00 UTC).

//Function that obtains the milliseconds elapsed since 1970-01-01
long	get_time_ms(void)
{
	struct timeval	time_value;

	gettimeofday(&time_value, NULL);
	return ((time_value.tv_sec * 1000L) + (time_value.tv_usec / 1000L));
}



int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5 || argc > 6)
		return (error_message(INVALID_NUM_INPUT, EXIT_FAILURE));
	if (!check_args(argc, argv))
		return (error_message(INVALID_INPUT, EXIT_FAILURE));	
	//INICIALIZAR LOS DATOS (incluido philos)
	init(&table, argv);
	//crear hilos x cada filo
	create_threads(&table);
		//return error y liberarrr???
	//pthread_create()
	//llamar a funcion monitor que controla estado de philos
	//monitor();
	//while join de los hilos. join is going to pause and wait here until this thread
	//has completed its work
	//clear_ft
	return (EXIT_SUCCESS);
}

/*
TODO
- OPTIMIZAR F(X) DE GET TIME
- MONITOREAR
- TENER EN CUENTA QUE EL TOT DE MENUS NO SE HAYA COMMPLETADO
- QUE HACER SI SON LOS FILOS IMPARES CON EL 1 Y EL N
- LIMPIAR TODO, LIBERAR TODO 
*/