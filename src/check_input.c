/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:47:57 by ctacconi          #+#    #+#             */
/*   Updated: 2024/08/02 18:48:52 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	error_message(char *str, int exit_num)
{
	printf("%s", str);
    return (exit_num);	
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	my_atoi(const char *str)
{
	int					i;
	unsigned long int	res;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (res > INT_MAX)
		return (-1);
	return ((int)res);
}

//Check that there are only digits
int	check_digit_format(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

//Check that only digits and valid arguments
int	check_args(int argc, char **argv)
{
	//SOLO digitos
	//los philos argv[1] no pueden ser mas de 200
	//argv[2], argv[3] y argv[4] mas de 60 max, int
	//el argv[opc] > 1
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		if (!check_digit_format(argv[i]))
			return (0);
		num = my_atoi(argv[i]); 
		if (i == 1 && (num < 1 || num > MAX_PHILOS))
			return (0);
		if (i == 5 && (num < 1 || num == -1 ))
			return (0);
		if ((i >= 2 && i <= 4) && (num < 60 || num == -1))
			return (0);
		i++;
	}
	return (1);
}