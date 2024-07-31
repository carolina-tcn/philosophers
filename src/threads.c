/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:11:08 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/31 13:52:37 by ctacconi         ###   ########.fr       */
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
	//pthread_t	controller;

	i = 0;
	//BLOQUEO UN MUTEX START_LOCK;
	pthread_mutex_lock(&table->start_lock);
	while (i < table->number_of_philosophers)
	{
		//TODO PROTEGER EL PTHREAD_CREATE. PUEDE DEVOLVER -1 SI ERROR
		pthread_create(&(table->philos[i]).thread, NULL, &philo_routine, (void *)&(table->philos[i]));
		i++;
	}
	//AQUI EMPIEZA EL START TIME
	table->start_time = get_time_ms();
	//DESBLOQUEAMOS EL MUTEX DE INICIO
	pthread_mutex_unlock(&table->start_lock);
	//monitoring();
	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
            //return (1), gestionar
		i++;
	}
    return (0);
}
