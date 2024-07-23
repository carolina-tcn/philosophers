/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:33:16 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/23 18:23:09 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philo.h"

int	check_digit_format(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_max_min(char *str)
{
		
}

int	check_args(int argc, char **argv)
{
	//SOLO digitos
	//los philos argv[1] no pueden ser mas de 200
	//argv[2], argv[3] y argv[4] mas de 60 max, int
	//el argv[opc] > 1
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		if (!check_digit_format(argv[i]))
			return (0);
		num = my_atoi(argv[i]);
		//printf("%i es el num que se obtiene de atoi\n", num); 
		if (i == 1 && (num < 1 || num > MAX_PHILOS))
		{
			//printf("entra en el segundo if\n");
			return (0);
		}
		if (i == 5 && (num < 1 || num == -1 ))
		{
			//printf("entra en el segundo if\n");
			return (0);
		}
		if ((i >= 2 && i <= 4) && (num < 60 || num == -1))
		{
			//printf("entra en el tercer if\n");
			return (0);
		}
		i++;
	}
	return (1);
}

/*int	create_philos(char **argv)
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
			//ft_lstadd_front(...)
		number_of_philosophers--;
	}
	return (1);
}*/
//ARREGLAR MAKEFILE
//RACE CONDITION can happen when 2 or more threads are trying to access and modify the same variable at the same time
//int	usleep(useconds_t usec)-> suspends execution of the calling thread
//for (at least) usec microseconds
//initialize and destroy the mutex, and you have to do that every time you want to use a mutex (destroy it after you finished using it)

int	error_message(char *str, int exit_num)
{
	printf("%s", str);
	return(exit_num);	
}

int	main(int argc, char **argv)
{
	//ANTES DE INICIALIZAR NADA, CHECK INPUT
	if (argc < 5 || argc > 6)
		return (error_message(NUM_INPUT, EXIT_FAILURE));
	if (!check_args(argc, argv))
		return (error_message(VALID_INPUT, EXIT_FAILURE));	
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
	return (EXIT_SUCCESS);
}