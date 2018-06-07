/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dezzeddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:55:15 by dezzeddi          #+#    #+#             */
/*   Updated: 2018/06/06 14:55:17 by dezzeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

t_flags		parse_flags(char *format, size_t *i)
{
	t_flags res;

	ft_bzero(&res, sizeof(t_flags));
	(*i)++;
	while (format[*i] == '+' || format[*i] == '-'
			|| format[*i] == '#' || format[*i] == ' ' ||
			format[*i] == '0')
	{
		if (format[*i] == '-')
			res.minus = 1;
		if (format[*i] == '+')
			res.plus = 1;
		if (format[*i] == ' ')
			res.space = 1;
		if (format[*i] == '0')
			res.zero = 1;
		if (format[*i] == '#')
			res.hashtag = 1;
		(*i)++;
	}
	return (res);
}

int			parse_width(char *fmt, size_t *i, va_list *ap, t_param *specif)
{
	int		res;
	size_t	j;

	j = *i;
	while (ft_isdigit(fmt[*i]))
		(*i)++;
	if (fmt[(*i)] == '*')
	{
		res = va_arg(*ap, int);
		if (res < 0)
		{
			res *= -1;
			specif->flags.minus = 1;
		}
		(*i)++;
	}
	else
		res = ft_atoi(fmt + j);
	return (res);
}

int			parse_precision(char *fmt, size_t *i, va_list *ap, t_param *specif)
{
	int	res;
	int	j;

	res = 0;
	if (fmt[(*i)] == '.')
	{
		specif->dot = 1;
		(*i)++;
		j = *i;
		while (ft_isdigit(fmt[*i]))
			(*i)++;
		if (fmt[(*i)] == '*')
		{
			res = va_arg(*ap, int);
			if (res < 0)
			{
				res *= -1;
				specif->flags.minus = 1;
			}
			(*i)++;
		}
		else
			res = ft_atoi(fmt + j);
	}
	return (res);
}

char		*parse_length(char *format, size_t *i)
{
	char	*res;

	res = ft_strnew(2);
	if (format[*i] == 'j' || format[*i] == 'z' || format[*i] == 't' ||
			format[*i] == 'L' || format[*i] == 'h' || format[*i] == 'l')
	{
		*res = format[(*i)++];
		if (format[*i] == 'l' || format[*i] == 'h')
		{
			*(++res) = format[(*i)];
			(*i)++;
			res--;
		}
	}
	return (res);
}
