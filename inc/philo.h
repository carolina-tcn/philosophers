/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:23:31 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/31 16:51:29 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h> //pthread_
# include <stdio.h> //printf
# include <unistd.h> //write, read, usleep
# include <stdlib.h> //malloc, EXIT_FAILURE, free
# include <limits.h> //MAX, MIN
# include <sys/time.h> //gettimeofday

# define MAX_PHILOS	200
# define INVALID_NUM_INPUT	"Invalid number of args: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philo_must_eat]\n"
# define INVALID_INPUT "Invalid arguments\n"
# define ALLOC_ERROR "Allocation error\n"

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					times_eat;
	long				last_meal;//time passed from last meal to die
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				*start_time;
	int					*dead;
	//struct s_table	*table;
	pthread_mutex_t		r_fork;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*start_lock;
}		t_philo;

typedef struct s_table
{
	int				dead_flag;
	long			start_time;
	int				number_of_philosophers;
	int				num_of_times_each_philo_must_eat;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	start_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}		t_table;

//Check_input
int	is_digit(char c);
int	my_atoi(const char *str);
int	check_digit_format(char *str);
int	check_args(int argc, char **argv);
int	error_message(char *str, int exit_num);

//Init
void    init(t_table *table, char **argv);

//Threads
int	create_threads(t_table *table);

//Actions
void	*philo_routine(void *param);
void    philo_eating(t_philo *philo);
void    philo_sleeping(t_philo *philo);
void    philo_thinking(t_philo *philo);

long	get_time_ms();


#endif