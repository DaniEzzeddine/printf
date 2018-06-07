/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dezzeddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:58:09 by dezzeddi          #+#    #+#             */
/*   Updated: 2018/06/06 13:58:12 by dezzeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_width(t_param *args)
{
	int		num;
	char	*str;

	num = args->width - args->l;
	num = (num < 0) ? 0 : num;
	str = ft_strnew(num);
	ft_memset(str, ' ', num);
	return (str);
}

char			*ft_handle_char(t_param *args, va_list *ap)
{
	char	*res;
	char	*prefix_postfix;
	char	temp;

	if (args->specifier != '%')
		temp = (char)va_arg(*ap, int);
	else
		temp = '%';
	args->l = 1;
	prefix_postfix = get_width(args);
	res = ft_strnew(ft_strlen(prefix_postfix) + 1);
	if (args->flags.minus)
	{
		*(res) = temp;
		ft_strcpy(res + 1, prefix_postfix);
	}
	else
	{
		ft_strcpy(res, prefix_postfix);
		res[ft_strlen(prefix_postfix)] = temp;
	}
	ft_memdel((void **)&prefix_postfix);
	args->l = !temp ? ft_strlen(res) + 1 : ft_strlen(res);
	return (res);
}
