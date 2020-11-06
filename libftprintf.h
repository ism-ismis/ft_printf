/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishirais <ishirais@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:32:38 by ishirais          #+#    #+#             */
/*   Updated: 2020/11/05 18:31:18 by ishirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <sys/errno.h>

typedef struct	s_flag
{
	int	flag[4];
	int	field;
	int	acc;
	int	spec;
	int	putlen;
}				t_flag;

int				ft_printf(const char *fmt, ...);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);

int				ft_atoi_rev(const char **fmt);
void			ft_putnbr(unsigned int nb, int *n, t_flag *s);
void			ft_putstr(char *str);

void			get_putlen_int(int num, t_flag *s);
void			get_putlen_p(unsigned long long num2, t_flag *s);
void			putnbr_hex(unsigned int nbr, t_flag *s);
void			putnbr_hex_p(unsigned long long nbr);

void			init_base(t_flag *s);
void			def_base(t_flag *s, const char **fmt);
void			def_field(t_flag *s, const char **fmt, va_list *ap);
void			def_acc(t_flag *s, const char **fmt, va_list *ap);
void			def_spec(t_flag *s, const char **fmt);

void			ft_putchar_rep(int count, char c);
void			print_int(int *n, t_flag *s, int num);

void			adjust_len_p(int *n, t_flag *s, unsigned long long num2);
void			adjust_len_s(int *n, t_flag *s);
void			print_hex_p(t_flag *s, unsigned long long num2);
void			print_per_s(int *n, t_flag *s, va_list *ap);

#endif
