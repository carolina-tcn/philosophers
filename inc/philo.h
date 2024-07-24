/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:23:31 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/24 16:52:37 by ctacconi         ###   ########.fr       */
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
# define INVALID_NUM_INPUT	"Invalid number of args: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philo_must_eat]\n"
# define INVALID_INPUT "Invalid input:\n./philo '<200'\t'>60'\t'>60'\t'>60'\t \
'>60'\t'>1'\n"

typedef struct s_philo
{
	pthread_t	thread_id;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int			num_of_times_to_eat;
	struct s_program	*program;

}		t_philo;

typedef struct s_program
{
	int		number_of_philosophers;
	t_philo	*philos;	
}		t_program;

//Check_input
int	is_digit(char c);
int	my_atoi(const char *str);
int	check_digit_format(char *str);
int	check_args(int argc, char **argv);
int	error_message(char *str, int exit_num)

#endif