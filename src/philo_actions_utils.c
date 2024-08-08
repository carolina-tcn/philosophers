/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:26:53 by ctacconi          #+#    #+#             */
/*   Updated: 2024/08/07 15:36:03 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	take_l_fork(t_philo *philo)
{
	long	action_time;

	pthread_mutex_lock(philo->l_fork);
	action_time = get_time_ms();
	write_action(philo, "has taken a fork", action_time);
}

void	take_r_fork(t_philo *philo)
{
	long	action_time;

	pthread_mutex_lock(&philo->r_fork);
	action_time = get_time_ms();
	write_action(philo, "has taken a fork", action_time);
}

void	eating_action_time(t_philo *philo)
{
	long	action_time;

	action_time = get_time_ms();
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = action_time;
	pthread_mutex_unlock(&philo->meal_lock);
	pthread_mutex_lock(&philo->meals_eaten_lock);
	philo->times_eat++;
	pthread_mutex_unlock(&philo->meals_eaten_lock);
	write_action(philo, "is eating", action_time);
	while (1)
	{
		if ((get_time_ms() - action_time) >= philo->time_to_eat)
			break ;
		usleep(100);
	}
}
