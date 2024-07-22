/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:23:31 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/22 21:25:32 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <pthread.h>
# include <stdio.h> //printf
# include <unistd.h> //write, read
# include <stdlib.h> //malloc, EXIT_FAILURE

typedef struct s_philo
{
	int		number_of_philosophers;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	int		num_of_times_to_eat;
	
}		t_philo;

typedef struct s_program
{

	t_philo	*philos;	
}		t_program;

# endif