/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:53:25 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/31 16:49:55 by ctacconi         ###   ########.fr       */
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
	
	//write_action(philo, "has taken a fork");
	//Intentar coger el segundo tenedor. al reves del primero
	
	//write_action(philo, "has taken a fork");

	
	//EMPIEZA LA ACCION GUARDAR TIEMPO BLABLA Y Guardar el last_meal
	
	//write_action(philo, "is eating");
	//Esperar el tiempo de comer
	
	//Soltar los dos tenedores con unlock
	
	//Salir
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
