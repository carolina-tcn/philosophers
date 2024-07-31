/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:53:25 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/31 18:10:52 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	write_action(t_philo *philo, char *str, long action_time)
{
	pthread_mutex_lock(philo->write_lock);
	printf("%ld %d %s \n", action_time - *philo->start_time, philo->id, str);
	pthread_mutex_unlock(philo->write_lock);	
}


void    philo_eating(t_philo *philo)
{
	//Coger un tenedor primero (mutex lock). Si es par intentar coger el de la derecha y si es impar la izquierda
		
	//Intentar coger el segundo tenedor. al reves del primero
	
	//EMPIEZA LA ACCION GUARDAR TIEMPO BLABLA Y Guardar el last_meal
	//Esperar el tiempo de comer
	//Soltar los dos tenedores con unlock
	//salir
	
	//PROBLEMA!!!si % 2!= 0 && numero de filos impares -> el 1 y N no pueden coger forks a la vez
	long action_time;

	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->r_fork);
		action_time = get_time_ms();
		write_action(philo, "has taken a fork", action_time);
		pthread_mutex_lock(philo->l_fork);
		action_time = get_time_ms();
		write_action(philo, "has taken a fork", action_time);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		action_time = get_time_ms();
		write_action(philo, "has taken a fork", action_time);
		pthread_mutex_lock(&philo->r_fork);
		action_time = get_time_ms();
		write_action(philo, "has taken a fork", action_time);
	}
	action_time = get_time_ms();
	write_action(philo, "is eating", action_time);
	while (1)
	{
		if ((get_time_ms() - action_time) > philo->time_to_eat)
			break ;
		usleep(100);//esto pa que no se vuelva fast and furious
	}
	philo->last_meal = (get_time_ms() - action_time);
	pthread_mutex_unlock(&philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void    philo_sleeping(t_philo *philo)
{
	long action_time;

	action_time = get_time_ms();
	write_action(philo, "is sleeping", action_time);
	while (1)
	{
		if ((get_time_ms() - action_time) > philo->time_to_sleep)
			break ;
		usleep(100);//esto pa que no se vuelva fast and furious
	}
	//Esperar a que pase el tiempo de dormir
	//Salir
}

void    philo_thinking(t_philo *philo)
{
	long action_time;

	action_time = get_time_ms();
	write_action(philo, "is thinking", action_time);
}
/*int	check_if_alive(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (0);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (1);
}*/
//The new thread starts execution by invoking start_routine(); void *(*start_routine)(void *)
void	*philo_routine(void *param)
{
    t_philo *philo;
	
    philo = (t_philo *)param;
	//MUTEX START_LOCK
	pthread_mutex_lock(philo->start_lock); ///todos los filosofos acumulados en cola
	pthread_mutex_unlock(philo->start_lock);
    //Casteo de void * a t_philo *
	if (philo->id % 2 == 0)
		usleep(500);//TIEMPO DE ESPERA DEL HILO (APROXIMADO)
	pthread_mutex_lock(philo->dead_lock);
	while (*philo->dead == 0)
    {
		pthread_mutex_unlock(philo->dead_lock);
 		//BUCLE MIENTRAS DEAD FLAG == 0 o MENUS COMPLETOS
		philo_eating(philo);
		philo_sleeping(philo);
    	philo_thinking(philo);
		pthread_mutex_lock(philo->dead_lock);
    }
	pthread_mutex_unlock(philo->dead_lock);
    return (NULL);
}
