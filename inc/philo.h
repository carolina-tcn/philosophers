/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:23:31 by ctacconi          #+#    #+#             */
/*   Updated: 2024/08/06 16:39:49 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h> //pthread_
# include <stdio.h> //printf
# include <unistd.h> //write, read, usleep
# include <stdlib.h> //malloc, EXIT_FAILURE, free
# include <limits.h> //MAX_INT, MIN_INT
# include <sys/time.h> //gettimeofday

# define MAX_PHILOS	200
# define INVALID_NUM_INPUT	"Invalid number of args: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philo_must_eat]\n"
# define INVALID_INPUT "Invalid arguments\n"
# define ALLOC_ERROR "Allocation error\n"
# define THREADS_ERROR "Error creating a thread\n"

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					times_eat;
	long				last_meal;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				*start_time;
	int					*dead;
	pthread_mutex_t		r_fork;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*write_lock;
	pthread_mutex_t		*dead_lock;
	pthread_mutex_t		*start_lock;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		meals_eaten_lock;
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
int		is_digit(char c);
int		my_atoi(const char *str);
int		check_digit_format(char *str);
int		check_args(int argc, char **argv);
int		error_message(char *str, int exit_num);

//Init
int		init(t_table *table, char **argv);

//Threads
int		create_threads(t_table *table);
void	join_threads(t_table *s_table);

//Actions
void	*philo_routine(void *param);
void	philo_eating(t_philo *philo);
void	philo_sleeping(t_philo *philo);
void	philo_thinking(t_philo *philo);
void	write_action(t_philo *philo, char *str, long action_time);
void	take_l_fork(t_philo *philo);
void	take_r_fork(t_philo *philo);
void	eating_action_time(t_philo *philo);

//Utils
int		ft_strncmp(const char *s1, const char *s2, size_t n);
long	get_time_ms(void);
void	ft_usleep(long milliseconds);

//Monitoring
void	monitoring(t_table *table);

#endif