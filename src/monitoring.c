/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:24:04 by ctacconi          #+#    #+#             */
/*   Updated: 2024/08/01 18:59:55 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//mirar si alguno ha muerto

int    check_if_dead(t_table *table)
{
    int i;

    while (i < table->number_of_philosophers)
    {
        pthread_mutex_lock(&table->meal_lock)
        if (pthread_mutex_lock(table->philos[i].last_meal))
        {
            pthread_mutex_lock(&table->dead_lock);
            table->dead_flag == 1;
            pthread_mutex_unlock(&table->dead_lock);
            return (1);
        }
        i++;    
    }
    return (0);
}

int    check_meals(t_table *table)
{
    int i;
    int philos_full;

    if (table->num_of_times_each_philo_must_eat != -1)
    {
        i = 0;
        philos_full = 0;

        while (i < table->number_of_philosophers)
        {
            pthread_mutex_lock(&table->philos[i].meals_eaten_lock);
            if (table->philos[i].times_eat == table->num_of_times_each_philo_must_eat)
                philos_full++;
            pthread_mutex_unlock(&table->philos[i].meals_eaten_lock);
            if (i + 1 == table->number_of_philosophers)
            {
                if (philos_full == table->num_of_times_each_philo_must_eat)
                {
                    pthread_mutex_lock(&table->dead_lock);
                    table->dead_flag = 1;
                    pthread_mutex_unlock(&table->dead_lock);
                    return (1);
                }
                
            }
            i++;
        }
        return (0);
    }
}

void    monitoring(t_table *table)
{
    while (1)
    {
        if (check_meals(table) || check_if_dead(table))
            return ;
        usleep(100);
    }
}