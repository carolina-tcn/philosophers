/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinatacconis <carolinatacconis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:31:38 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/30 13:21:47 by carolinatac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    philos_init(t_program *table, char **argv)
{
    int i;

    i = 0;
    
    while (i < table->number_of_philosophers)
    {
        table->philos[i].id = i + 1;
        table->philos[i].times_eat = 0;
        table->philos[i].time_to_die = my_atoi(argv[2]);
	    table->philos[i].time_to_eat = my_atoi(argv[3]);
        table->philos[i].time_to_sleep = my_atoi(argv[4]);
        table->philos[i].dead = &(table->dead_flag);
        table->philos[i].table = table;
        pthread_mutex_init(&(table->philos[i].r_fork), NULL);
        if (i == 0)
            table->philos[i].l_fork = &(table->philos[table->number_of_philosophers - 1].r_fork);
        else
            table->philos[i].l_fork = &(table->philos[i - 1].r_fork);
        //table->philos[i].write_lock = &(table->write_lock);
        // table->philos[i].dead_lock = &(table->dead_lock);
        // table->philos[i].meal_lock = &(table->meal_lock);
        i++;
    }
}

void    table_init(t_program *table, char **argv)
{
    table->dead_flag = 0;
    table->number_of_philosophers = my_atoi(argv[1]);
    table->philos = malloc(sizeof(t_philo) * table->number_of_philosophers);
    if (!table->philos)
    {
        printf("%s", ALLOC_ERROR);
        //gestionar error
    }
    if (argv[5])
	    table->num_of_times_each_philo_must_eat = my_atoi(argv[5]);
    else
        table->num_of_times_each_philo_must_eat = -1;
    pthread_mutex_init(&(table->dead_lock), NULL);
    pthread_mutex_init(&(table->write_lock), NULL);
    pthread_mutex_init(&(table->meal_lock), NULL);
}

void    init(t_program *table, char **argv)
{
    table_init(&table, argv);
    philos_init(&table, argv);
}