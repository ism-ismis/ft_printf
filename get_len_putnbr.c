/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len_putbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishirais <ishirais@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:00:25 by ishirais          #+#    #+#             */
/*   Updated: 2020/11/05 15:03:31 by ishirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	cal_putlen(unsigned int num, t_flag *s, unsigned int base)
{
	if (num == 0)
		s->putlen += 1;
	while (num > 0)
	{
		num /= base;
		s->putlen += 1;
	}
}

void	get_putlen_int(int num, t_flag *s)
{
	unsigned int	num2;

	if (s->spec == 0)
		s->putlen = 1;
	else if (s->spec == 1)
	{
		if (num < 0)
		{
			s->putlen += 1;
			num2 = num * -1;
		}
		else
			num2 = num;
		cal_putlen(num2, s, 10);
	}
	else
	{
		num2 = num;
		if (s->spec == 2)
			cal_putlen(num2, s, 10);
		else
			cal_putlen(num2, s, 16);
	}
}

void	get_putlen_p(unsigned long long num2, t_flag *s)
{
	if (num2 == 0)
		s->putlen = 1;
	while (num2 > 0)
	{
		num2 /= 16;
		s->putlen += 1;
	}
}

void	putnbr_hex(unsigned int nbr, t_flag *s)
{
	char	*low;
	char	*up;
	char	*p;

	low = "0123456789abcdef";
	up = "0123456789ABCDEF";
	if (s->spec == 4)
		p = up;
	else
		p = low;
	if (nbr < 16)
		write(1, &(p[nbr]), 1);
	else
	{
		putnbr_hex((nbr / 16), s);
		write(1, &(p[nbr % 16]), 1);
	}
}

void	putnbr_hex_p(unsigned long long nbr)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nbr < 16)
		write(1, &(hex[nbr]), 1);
	else
	{
		putnbr_hex_p((nbr / 16));
		write(1, &(hex[nbr % 16]), 1);
	}
}
