/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dezzeddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:59:38 by dezzeddi          #+#    #+#             */
/*   Updated: 2018/06/06 13:59:38 by dezzeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_width(t_param *args)
{
	int		num;
	char	*str;

	if (args->precision > 0 && args->precision < args->l)
		num = args->width - args->precision;
	else
		num = args->width - args->l;
	num = (num < 0) ? 0 : num;
	str = ft_strnew(num);
	ft_memset(str, ' ', num);
	return (str);
}

static char		*get_precision(t_param *args, char *temp)
{
	char	*str;

	if (args->precision > 0 && args->precision < args->l)
		str = ft_strsub(temp, 0, args->precision);
	else
		str = ft_strsub(temp, 0, args->l);
	return (str);
}

char			*ft_handle_str(t_param *args, va_list *ap)
{
	char	*res;
	char	*value_to_print;
	char	*prefix_postfix;
	char	*temp;

	temp = va_arg(*ap, char *);
	if (!(temp))
		temp = "(null)";
	args->l = ft_strlen(temp);
	value_to_print = get_precision(args, temp);
	prefix_postfix = get_width(args);
	if (args->flags.minus)
		res = ft_strjoin(value_to_print, prefix_postfix);
	else
		res = ft_strjoin(prefix_postfix, value_to_print);
	args->l = ft_strlen(res);
	return (res);
}
