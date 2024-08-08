/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:53:25 by ctacconi          #+#    #+#             */
/*   Updated: 2024/08/07 16:21:30 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		take_l_fork(philo);
		take_r_fork(philo);
	}
	else
	{
		take_r_fork(philo);
		if (philo->l_fork)
			take_l_fork(philo);
		else
		{
			usleep(philo->time_to_die * 1500);
			pthread_mutex_unlock(&philo->r_fork);
			return ;
		}
	}
	eating_action_time(philo);
	pthread_mutex_unlock(&philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	philo_sleeping(t_philo *philo)
{
	long	action_time;

	action_time = get_time_ms();
	write_action(philo, "is sleeping", action_time);
	usleep(philo->time_to_sleep * 1000);
}

void	philo_thinking(t_philo *philo)
{
	long	action_time;

	action_time = get_time_ms();
	write_action(philo, "is thinking", action_time);
}

//The new thread starts execution by invoking start_routine()
void	*philo_routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	pthread_mutex_lock(philo->start_lock);
	pthread_mutex_unlock(philo->start_lock);
	pthread_mutex_lock(philo->dead_lock);
	while (*philo->dead == 0)
	{
		pthread_mutex_unlock(philo->dead_lock);
		philo_eating(philo);
		philo_sleeping(philo);
		philo_thinking(philo);
		pthread_mutex_lock(philo->dead_lock);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (NULL);
}
