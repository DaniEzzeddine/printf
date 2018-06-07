/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dezzeddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:55:48 by dezzeddi          #+#    #+#             */
/*   Updated: 2018/06/06 14:56:00 by dezzeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void			del_mem(t_param *args)
{
	if (!args)
		return ;
	ft_strdel(&(args->length));
	ft_memdel((void **)&args);
}

t_param			*parse_params(char *format, va_list *ap, size_t *i)
{
	t_param *res;

	res = malloc(sizeof(t_param));
	ft_bzero(res, sizeof(t_param));
	res->flags = parse_flags(format, i);
	res->width = parse_width(format, i, ap, res);
	res->precision = parse_precision(format, i, ap, res);
	res->length = parse_length(format, i);
	res->specifier = format[(*i)];
	return (res);
}

size_t			size_of_final_str(char *format, va_list *ap)
{
	t_param		*param;
	size_t		size;
	size_t		i;

	size = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			param = parse_params((char *)format, ap, &i);
			size = size + ft_algo(param, ap);
			del_mem(param);
		}
		else
		{
			write(1, (format + i), 1);
			size++;
		}
		i++;
	}
	return (size);
}

int				ft_printf(char *format, ...)
{
	va_list		ap;
	int			size;

	va_start(ap, format);
	size = (int)size_of_final_str(format, &ap);
	va_end(ap);
	return (size);
}
