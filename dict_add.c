/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishirais <ishirais@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:51:36 by ishirais          #+#    #+#             */
/*   Updated: 2020/11/05 23:36:54 by ishirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

void				ft_putnbr(unsigned int nb2, int *n, t_flag *s)
{
	if (nb2 / 10 == 0)
		ft_putchar(nb2 + '0');
	else
	{
		ft_putnbr(nb2 / 10, n, s);
		ft_putchar(nb2 % 10 + '0');
	}
}

static long long	overflow_check(long long n, int sign)
{
	if (errno != ERANGE)
		return (n);
	if (sign == 1)
		return (-1);
	return (0);
}

int					ft_atoi_rev(const char **fmt)
{
	int				sign;
	long long		res;

	sign = 1;
	res = 0;
	if (**fmt == '-')
	{
		sign = -1;
		(*fmt)++;
	}
	while (**fmt && ft_isdigit(**fmt))
	{
		if (res)
			res *= 10;
		res += **fmt - '0';
		res = overflow_check(res, sign);
		(*fmt)++;
	}
	return (res * sign);
}

void				ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
