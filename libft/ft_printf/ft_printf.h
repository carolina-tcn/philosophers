/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:56:00 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/18 19:09:08 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *formato, ...);
void	ft_put_unbr(unsigned int n, int *len);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putnbr(int number, int *len);
void	ft_puthex(unsigned int num, char c, int *len);
void	ft_putptr(unsigned long ptr, int *len);

#endif
