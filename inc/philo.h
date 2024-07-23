/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:23:31 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/23 18:59:29 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h> //printf
# include <unistd.h> //write, read
# include <stdlib.h> //malloc, EXIT_FAILURE
# include <limits.h> //MAX, MIN

# define MAX_PHILOS	200
# define NUM_INPUT	"Invalid number of args: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philo_must_eat]\n"
# define VALID_INPUT "Invalid input:\n./philo '<200'\t'>60'\t'>60'\t'>60'\t'>60'\t'>1'\n"

typedef struct s_philo
{
	pthread_t	thread;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	int		num_of_times_to_eat;
	
}		t_philo;

typedef struct s_program
{
	int	number_of_philosophers;
	t_philo	*philos;	
}		t_program;

int is_digit(char c);
int	my_atoi(const char *str);

# endif