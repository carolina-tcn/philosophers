/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:11:08 by ctacconi          #+#    #+#             */
/*   Updated: 2024/08/01 19:09:40 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//int pthread_create(pthread_t *restrict thread, const pthread_attr_t *restrict attr, void *(*start_routine)(void *), void *restrict arg);

//Function that creats a thread per philosopher
int	create_threads(t_table *table)
{
	int			i;

	i = 0;

	pthread_mutex_lock(&table->start_lock);
	while (i < table->number_of_philosophers)
	{
		//printf("creo hilo numero %d\n", i);
		//TODO PROTEGER EL PTHREAD_CREATE. PUEDE DEVOLVER -1 SI ERROR
		pthread_create(&(table->philos[i]).thread, NULL, &philo_routine, (void *)&(table->philos[i]));
		i++;
	}
	//AQUI EMPIEZA EL START TIME
	table->start_time = get_time_ms();
	//DESBLOQUEAMOS EL MUTEX DE INICIO
	pthread_mutex_unlock(&table->start_lock);
    return (0);
}
