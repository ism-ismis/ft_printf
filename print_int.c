/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishirais <ishirais@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:03:43 by ishirais          #+#    #+#             */
/*   Updated: 2020/11/06 00:09:27 by ishirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar_rep(int count, char c)
{
	while (count--)
		write(1, &c, 1);
}

void	adjust_len_int(int *n, t_flag *s, int num)
{
	if (s->flag[3] == 0 && s->acc == -1 && s->field == -1)
	{
		s->acc = 0;
		s->field = 0;
		*n += s->putlen;
		return ;
	}
	if (s->flag[3] && (s->acc == -1 || num == 0))
		s->putlen = 0;
	if (num < 0 && (s->spec == 1))
	{
		s->putlen--;
		s->acc = s->acc > s->putlen ? s->acc - s->putlen : 0;
		s->field = s->field > (s->acc + s->putlen)
		? s->field - (s->acc + s->putlen) - 1 : 0;
		*n += s->putlen + s->field + s->acc + 1;
	}
	else
	{
		s->field = (s->field > s->putlen) ? s->field - s->putlen : 0;
		s->acc = (s->acc > s->putlen) ? s->acc - s->putlen : 0;
		s->field = (s->field > s->acc) ? s->field - s->acc : 0;
		*n += s->putlen + s->field + s->acc;
	}
}

void	print_putlen(int *n, t_flag *s, int num)
{
	char			p;
	unsigned int	unum;

	if (s->spec == 0)
	{
		p = (char)num;
		write(1, &p, 1);
	}
	else if (s->spec == 1)
	{
		if (num < 0)
			unum = num * -1;
		else
			unum = num;
		ft_putnbr(unum, n, s);
	}
	else if (s->spec >= 2 && s->spec <= 4)
	{
		unum = (unsigned int)num;
		if (s->spec == 2)
			ft_putnbr(unum, n, s);
		else
			putnbr_hex(unum, s);
	}
}

void	print_flag_one(int *n, t_flag *s, int num)
{
	if (s->flag[3])
	{
		ft_putchar_rep(s->field, ' ');
		if (s->spec == 1 && num < 0)
			write(1, "-", 1);
	}
	else
	{
		if (s->spec == 1 && num < 0)
			write(1, "-", 1);
		ft_putchar_rep(s->field, '0');
	}
	ft_putchar_rep(s->acc, '0');
	if (s->putlen)
		print_putlen(n, s, num);
}

void	print_int(int *n, t_flag *s, int num)
{
	adjust_len_int(n, s, num);
	if (s->flag[0] || (s->flag[0] && s->flag[1]))
	{
		if (s->spec == 1 && num < 0)
			write(1, "-", 1);
		ft_putchar_rep(s->acc, '0');
		if (s->putlen)
			print_putlen(n, s, num);
		ft_putchar_rep(s->field, ' ');
	}
	else if (s->flag[1])
		print_flag_one(n, s, num);
	else
	{
		ft_putchar_rep(s->field, ' ');
		if (s->spec == 1 && num < 0)
			write(1, "-", 1);
		ft_putchar_rep(s->acc, '0');
		if (s->putlen)
			print_putlen(n, s, num);
	}
}
