/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:33:16 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/22 21:28:15 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philo.h"

int	check_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (0);
		
	return (1);
}
int	create_philos(char **argv)
{
	t_philosopher	*new_philosopher;
	t_philosopher	*tmp;
	int				number_of_philosophers;
	int				id;
	
	number_of_philosophers = ft_atoi(argv[1]);
	if (number_of_philosophers <= 0)
		return (0);
	while (number_of_philosophers > 0)
	{
		new_philosopher = malloc(sizeof(t_philosopher));
		if (!new_philosopher)
				return (0);
		new_philosopher->num = 0;
		new_philosopher->next = NULL;
			//ft_lstadd_front( , new_philosopher)
		number_of_philosophers--;
	}
	return (1);
}
//RACE CONDITION can happen when 2 or more threads are trying to access and modify the same variable at the same time
//int	usleep(useconds_t usec)-> suspends execution of the calling thread
//for (at least) usec microseconds
//initialize and destroy the mutex, and you have to do that every time you want to use a mutex (destroy it after you finished using it)

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (argc < 4 || argc > 5)
	{	write(2, "Number of arguments: 4 or 5\n", 28);
		exit(EXIT_FAILURE);
	}
		
	if (!check_args(argc, argv))
	{
		
	}
	
	//los argv son:
	//	1.number_of_philosophers
	//	2.time_to_die
	//	3.time_to_eat
	//	4.time_to_sleep
	//	5.(number_of_times_each_philosopher_must_eat)
	
	//crear hilos x cada filo
		//create_philos
	//assign_ids_philo
	//
	//crear e inicializar mutex para los tenedores
	//
	//cada filo alterna entre pensar y comer
	//
	//clear_philos
	return (0);
}
