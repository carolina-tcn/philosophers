/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:33:16 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/24 21:38:32 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*int	create_philos(char **argv)
{
	t_philo		*philos;
	int				number_of_philosophers;
	
	t_philosopher	*new_philosopher;
	t_philosopher	*tmp;
	int				number_of_philosophers;
	int				id;
	
	number_of_philosophers = ft_atoi(argv[1]);
	if (number_of_philosophers <= 0)
		return (0);
	philos = malloc(number_of_philosophers * sizeof(t_philo));
	while (number_of_philosophers > 0)
	{
		new_philosopher = malloc(sizeof(t_philosopher));
		if (!new_philosopher)
				return (0);
		new_philosopher->num = 0;
		new_philosopher->next = NULL;
			//ft_lstadd_front(...)
		number_of_philosophers--;
	}
	return (1);
}
//ARREGLAR MAKEFILE
//RACE CONDITION can happen when 2 or more threads are trying to access and modify the same variable at the same time
//int	usleep(useconds_t usec)-> suspends execution of the calling thread
//for (at least) usec microseconds
//initialize and destroy the mutex, and you have to do that every time you want to use a mutex (destroy it after you finished using it)
*/

void	write()
{
	pthread_mutex_lock(write_lock);
	//escribir  el mensaje
	pthread_mutex_unlock(write_lock);	
}

void	threads_routine(void *param)
{
	//Casteo de void * a t_philo *
	
 	//BUCLE MIENTRAS DEAD FLAG == 0 o MENUS COMPLETOS
	//FUNCION COMER
	//FUNCION DORMIR
	//FUNCION PENSAR

	
}

void	create_threads(t_program *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_create(table->philos[i].thread, NULL, &threads_routine, &(table->philos[i]));
		i++;
	}
}

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

	pthread_create()
	//llamar a funcion monitor que controla estado de philos
	monitor();
	//while join de los hilos
	//clear_philos
	return (EXIT_SUCCESS);
}