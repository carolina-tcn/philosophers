/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:11:08 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/29 21:31:27 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//The new thread starts execution by invoking start_routine(); void *(*start_routine)(void *)
void	*philo_routine(void *param)
{
    t_philo *philo;
	
    philo = (t_philo *)param;
    //Casteo de void * a t_philo *
	while (*(philo->dead) == 0)
    {  
 	//BUCLE MIENTRAS DEAD FLAG == 0 o MENUS COMPLETOS
	philo_eating(philo);
    
	philo_sleeping(philo);
    philo_thinking(philo);
	
    }
    return (NULL);
}

//int pthread_create(pthread_t *restrict thread, const pthread_attr_t *restrict attr, void *(*start_routine)(void *), void *restrict arg);

//Function that creats a thread per philosopher
int	create_threads(t_program *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (pthread_create(table->philos[i].thread, NULL, &philo_routine, (void *)&(table->philos[i])) != 0)
            return (0);
		i++;
	}
    return (1);
}
