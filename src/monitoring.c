/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:24:04 by ctacconi          #+#    #+#             */
/*   Updated: 2024/08/02 19:28:23 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//Checks if the dead_flag == 1, means that a philospoher has died
int check_if_dead(t_table *table)
{
    int i;

    i = 0;
    while (i < table->number_of_philosophers)
    {
        pthread_mutex_lock(&table->philos[i].meal_lock);
        if (get_time_ms() - table->philos[i].last_meal >= table->philos[i].time_to_die)
        {
            pthread_mutex_unlock(&table->philos[i].meal_lock);
            pthread_mutex_lock(&table->dead_lock);
            table->dead_flag = 1;
            pthread_mutex_unlock(&table->dead_lock);
            write_action(&table->philos[i], "is dead", get_time_ms());
            return (1);
        }
        pthread_mutex_unlock(&table->philos[i].meal_lock);
        i++;    
    }
    return (0);
}

//Checks if all the philosophers has already eaten the argv(optional)
int check_meals(t_table *table)
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
            i++;
        }
        if (philos_full == table->number_of_philosophers)
        {
            pthread_mutex_lock(&table->dead_lock);
            table->dead_flag = 1;
            pthread_mutex_unlock(&table->dead_lock);
            return (1);
        }
    }
    return (0);
}

//Monitoring in a loop if the simulation has to end
void    monitoring(t_table *table)
{
    while (1)
    {
        if (check_meals(table) || check_if_dead(table))
            return ;
        usleep(100);
    }
}
