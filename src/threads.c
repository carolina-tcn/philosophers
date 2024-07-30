/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinatacconis <carolinatacconis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:11:08 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/30 19:05:54 by carolinatac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*monitoring(void *param)
{
	return(NULL);
}
//int pthread_create(pthread_t *restrict thread, const pthread_attr_t *restrict attr, void *(*start_routine)(void *), void *restrict arg);

//Function that creats a thread per philosopher
int	create_threads(t_table *table)
{
	int			i;
	pthread_t	controller;

	i = 0;
	if (pthread_create(&controller, NULL, &monitoring, table->philos) != 0)
		/* code */
	while (i < table->number_of_philosophers)
	{
		if (pthread_create(&(table->philos[i]).thread, NULL, &philo_routine, (void *)&(table->philos[i])) != 0)
            //return (1), gestionar
		i++;
	}
	if (pthread_join(controller, NULL) != 0)
		//gestionar
	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
            //return (1), gestionar
		i++;
	}
    return (0);
}
