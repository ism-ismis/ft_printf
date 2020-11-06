/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishirais <ishirais@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:05:33 by ishirais          #+#    #+#             */
/*   Updated: 2020/11/05 23:40:50 by ishirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_base(t_flag *s)
{
	s->flag[0] = 0;
	s->flag[1] = 0;
	s->flag[2] = 0;
	s->flag[3] = 0;
	s->field = -1;
	s->acc = -1;
	s->spec = -1;
	s->putlen = 0;
}

void	def_base(t_flag *s, const char **fmt)
{
	while (**fmt == '-' || **fmt == '0')
	{
		if (**fmt == '-')
			s->flag[0] = 1;
		else if (**fmt == '0')
			s->flag[1] = 1;
		(*fmt)++;
	}
}

void	def_field(t_flag *s, const char **fmt, va_list *ap)
{
	if (**fmt == '*')
	{
		s->flag[2] = 1;
		s->field = (va_arg(*ap, int));
		if (s->field < 0)
		{
			s->field *= -1;
			s->flag[0] = 1;
		}
		(*fmt)++;
	}
	else
		s->field = ft_atoi_rev(fmt);
}

void	def_acc(t_flag *s, const char **fmt, va_list *ap)
{
	if (**fmt == '.')
	{
		s->flag[3] = 1;
		(*fmt)++;
	}
	if (s->flag[3] && **fmt == '*')
	{
		s->flag[2] = 1;
		s->acc = (va_arg(*ap, int));
		if (s->acc < 0)
			s->flag[3] = 0;
		(*fmt)++;
	}
	else if (s->flag[3])
	{
		s->acc = (ft_atoi_rev(fmt));
		if (s->acc < 0)
			s->flag[3] = 0;
	}
}

void	def_spec(t_flag *s, const char **fmt)
{
	if (**fmt == 'c')
		s->spec = 0;
	else if (**fmt == 'd' || **fmt == 'i')
		s->spec = 1;
	else if (**fmt == 'u')
		s->spec = 2;
	else if (**fmt == 'x')
		s->spec = 3;
	else if (**fmt == 'X')
		s->spec = 4;
	else if (**fmt == 's')
		s->spec = 5;
	else if (**fmt == 'p')
		s->spec = 6;
	else if (**fmt == '%')
	{
		s->spec = 7;
		s->putlen = 1;
	}
	if (s->spec != -1)
		(*fmt)++;
}
