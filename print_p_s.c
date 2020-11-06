/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishirais <ishirais@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:01:31 by ishirais          #+#    #+#             */
/*   Updated: 2020/11/06 00:17:52 by ishirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	adjust_len_p(int *n, t_flag *s, unsigned long long num2)
{
	*n += 2;
	if (s->flag[3] == 0 && s->acc == -1 && s->field == -1)
	{
		s->acc = 0;
		s->field = 0;
		*n += s->putlen;
		return ;
	}
	if (s->flag[3] && (s->acc == -1 || num2 == 0))
		s->putlen = 0;
	s->field = (s->field > s->putlen + 2) ? s->field - s->putlen - 2 : 0;
	s->acc = (s->acc > s->putlen) ? s->acc - s->putlen : 0;
	s->field = (s->field >= s->acc + 2) ? s->field - s->acc : 0;
	*n += s->putlen + s->field + s->acc;
}

void	adjust_len_s(int *n, t_flag *s)
{
	if (s->acc == -1)
		s->acc = 0;
	if (s->flag[3])
		s->putlen = (s->putlen > s->acc) ? s->acc : s->putlen;
	s->field = (s->putlen < s->field) ? s->field - s->putlen : 0;
	*n += s->putlen + s->field;
}

void	print_hex_p(t_flag *s, unsigned long long num2)
{
	if (s->flag[0] || (s->flag[0] && s->flag[1]))
	{
		ft_putstr("0x");
		ft_putchar_rep(s->acc, '0');
		if (s->putlen)
			putnbr_hex_p(num2);
		ft_putchar_rep(s->field, ' ');
	}
	else
	{
		ft_putchar_rep(s->field, ' ');
		ft_putstr("0x");
		ft_putchar_rep(s->acc, '0');
		if (s->putlen)
			putnbr_hex_p(num2);
	}
}

void	print_per_s(int *n, t_flag *s, va_list *ap)
{
	const char			*ptr;

	ptr = va_arg(*ap, char *);
	if (ptr == NULL)
		ptr = "(null)";
	s->putlen = ft_strlen(ptr);
	adjust_len_s(n, s);
	if (s->flag[0])
	{
		write(1, ptr, s->putlen);
		ft_putchar_rep(s->field, ' ');
	}
	else
	{
		if (s->flag[1])
			ft_putchar_rep(s->field, '0');
		else
			ft_putchar_rep(s->field, ' ');
		write(1, ptr, s->putlen);
	}
}
