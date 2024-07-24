/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:31:38 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/24 21:23:21 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    init_philos(t_program *table, char **argv)
{
    int i;

    i = 0;
    table->philos = malloc(sizeof(t_philo) * table->number_of_philosophers);    
    while (i < table->number_of_philosophers)
    {
        table->philos[i].id = i + 1;
        table->philos[i].times_eat = 0;
        table->philos[i].time_to_die = my_atoi(argv[2]);
	    table->philos[i].time_to_eat = my_atoi(argv[3]);
        table->philos[i].time_to_sleep = my_atoi(argv[4]);
        table->philos[i].dead = &(table->dead_flag);
        pthread_mutex_init(&(table->philos[i].r_fork), NULL);
        if (i == 0)
            table->philos[i].l_fork = &(table->philos[table->number_of_philosophers - 1].r_fork);
        else
            table->philos[i].l_fork = &(table->philos[i - 1].r_fork);
        table->philos[i].write_lock = &(table->write_lock);
        table->philos[i].dead_lock = &(table->dead_lock);
        table->philos[i].meal_lock = &(table->meal_lock);
        i++;
    }
}

void    init(t_program *table, int argc, char **argv)
{
	table->number_of_philosophers = my_atoi(argv[1]);
    table->dead_flag = 0;
    if (argv[5])
	    table->num_of_times_each_philo_must_eat = my_atoi(argv[5]);
    else
        table->num_of_times_each_philo_must_eat = -1; 
    pthread_mutex_init(&(table->dead_lock), NULL);
    pthread_mutex_init(&(table->write_lock), NULL);
    pthread_mutex_init(&(table->meal_lock), NULL);

    init_philos(table, argv);
    
      
	printf("num filos: %i\n", table->number_of_philosophers);
    printf("time en morir: %i\n", table->time_to_die);
    printf("time en comer: %i\n", table->time_to_eat);
    printf("time en dormir: %i\n", table->time_to_sleep);	
    printf("cada filo tiene que comer: %i\n", table->num_of_times_each_philo_must_eat);	
}