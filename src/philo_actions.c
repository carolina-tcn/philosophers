/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinatacconis <carolinatacconis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:53:25 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/30 17:22:42 by carolinatac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    philo_eating(t_philo *philo)
{
    return ;
}

void    philo_spleeping(t_philo *philo)
{
    return ;
}

void    philo_thinking(t_philo *philo)
{
    return ;
}
int	check_if_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(&philo->table->dead_lock);
		return (0);
	}
	pthread_mutex_unlock(&philo->table->dead_lock);
	return (1);
}
//The new thread starts execution by invoking start_routine(); void *(*start_routine)(void *)
void	*philo_routine(void *param)
{
    t_philo *philo;
	
    philo = (t_philo *)param;
    //Casteo de void * a t_philo *
	if (philo->id % 2 == 0)
		usleep(500);//????
	while (check_if_alive(philo))
    {
 	//BUCLE MIENTRAS DEAD FLAG == 0 o MENUS COMPLETOS
	philo_eating(philo);
	philo_spleeping(philo);
    philo_thinking(philo);
    }
    return (param);
}
