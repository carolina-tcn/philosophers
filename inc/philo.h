/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinatacconis <carolinatacconis@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:23:31 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/30 17:20:57 by carolinatac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h> //printf
# include <unistd.h> //write, read, usleep
# include <stdlib.h> //malloc, EXIT_FAILURE
# include <limits.h> //MAX, MIN

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
	long				last_meal;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				start_time;
	int					*dead;
	struct s_program	*table;
	pthread_mutex_t		r_fork;
	pthread_mutex_t		*l_fork;
	//pthread_mutex_t	*write_lock;
	//pthread_mutex_t	*dead_lock;
	//pthread_mutex_t	*meal_lock;
}		t_philo;

typedef struct s_program
{
	int				dead_flag;
	int				number_of_philosophers;
	int				num_of_times_each_philo_must_eat;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}		t_program;

//Check_input
int	is_digit(char c);
int	my_atoi(const char *str);
int	check_digit_format(char *str);
int	check_args(int argc, char **argv);
int	error_message(char *str, int exit_num);

//Init
void    init(t_program *table, char **argv);

//Threads
int	create_threads(t_program *table);

//Actions
void	*philo_routine(void *param);
void    philo_eating(t_philo *philo);
void    philo_spleeping(t_philo *philo);
void    philo_thinking(t_philo *philo);




#endif