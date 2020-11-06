/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishirais <ishirais@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:53:04 by ishirais          #+#    #+#             */
/*   Updated: 2020/11/05 23:52:49 by ishirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_str(const char **start, const char **fmt, int *n)
{
	while (**fmt != '%' && **fmt)
		(*fmt)++;
	write(1, *start, *fmt - *start);
	*n += *fmt - *start;
}

void	print_percent(int *n, t_flag *s)
{
	s->field = (s->field > s->putlen) ? s->field - s->putlen : 0;
	*n += s->field + s->putlen;
	if (s->flag[0] || (s->flag[0] && s->flag[1]))
	{
		write(1, "%%", 1);
		ft_putchar_rep(s->field, ' ');
	}
	else if (s->flag[1])
	{
		ft_putchar_rep(s->field, '0');
		write(1, "%%", 1);
	}
	else
	{
		ft_putchar_rep(s->field, ' ');
		write(1, "%%", 1);
	}
}

void	print_per(int *n, t_flag *s, va_list *ap)
{
	int					num;
	unsigned long long	num2;

	num = 0;
	if (s->spec >= 0 && s->spec <= 4)
	{
		num = va_arg(*ap, int);
		get_putlen_int(num, s);
		print_int(n, s, num);
	}
	else if (s->spec == 5)
		print_per_s(n, s, ap);
	else if (s->spec == 6)
	{
		num2 = (unsigned long long)va_arg(*ap, void *);
		get_putlen_p(num2, s);
		adjust_len_p(n, s, num2);
		print_hex_p(s, num2);
	}
	else if (s->spec == 7)
		print_percent(n, s);
	else
		*n = -1;
}

void	proc_per(const char **fmt, int *n, va_list *ap)
{
	t_flag	s;

	(*fmt)++;
	init_base(&s);
	def_base(&s, fmt);
	def_field(&s, fmt, ap);
	def_acc(&s, fmt, ap);
	def_spec(&s, fmt);
	print_per(n, &s, ap);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			n;
	const char	*start;

	n = 0;
	va_start(ap, fmt);
	if (fmt == NULL)
		n = -1;
	while (n >= 0 && *fmt)
	{
		start = fmt;
		if (*start != '%')
			print_str(&start, &fmt, &n);
		else
			proc_per(&fmt, &n, &ap);
	}
	va_end(ap);
	return (n);
}
