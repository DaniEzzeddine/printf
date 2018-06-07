/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dezzeddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:52:58 by dezzeddi          #+#    #+#             */
/*   Updated: 2018/06/06 13:53:00 by dezzeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_digits(long long n)
{
	int			i;
	long long	temp;

	temp = n;
	i = 1;
	if (temp < 0)
		temp = -temp;
	while (temp > 9)
	{
		temp /= 10;
		i++;
	}
	return (i);
}

static char		*convert_to_memory_type(unsigned long long n)
{
	char		*res;
	char		*start_of_string;
	char		*str;

	start_of_string = malloc(sizeof(char) * 2 + 1);
	ft_bzero(start_of_string, 3);
	str = ft_itoa_base_for_uint(n, 16, 'x');
	res = ft_strjoin(start_of_string, str);
	return (res);
}

static char		*get_precision(t_param *args, long long n)
{
	char	*temp;
	char	*res;
	char	*start_of_res;
	int		dig_to_print;
	int		num_of_dig;

	num_of_dig = count_digits(n);
	dig_to_print = args->precision > num_of_dig ? args->precision : num_of_dig;
	res = ft_strnew(dig_to_print + 1);
	start_of_res = res;
	while (args->precision > num_of_dig++)
		*(res++) = '0';
	if (n < 0)
		n = -n;
	temp = convert_to_memory_type(n);
	ft_strcpy(res, temp);
	args->l = ft_strlen(start_of_res);
	ft_memdel((void **)&temp);
	return (start_of_res);
}

static char		*get_width(t_param *args)
{
	char	*res;
	char	*start_of_res;
	int		sym_to_print;
	int		check_for_zero;
	char	zero_or_space;

	check_for_zero = 0;
	if (!args->dot && !args->flags.minus && args->flags.zero)
		check_for_zero = 1;
	sym_to_print = args->width > args->l ? args->width : 0;
	res = ft_strnew(sym_to_print + 1);
	start_of_res = res;
	zero_or_space = (check_for_zero ? '0' : ' ');
	if (sym_to_print)
		while (sym_to_print > args->l++)
			*(res++) = zero_or_space;
	return (start_of_res);
}

char			*ft_handle_addr(t_param *args, va_list *ap)
{
	char				*res;
	char				*value_to_print;
	char				*prefix_postfix;
	unsigned long long	n;
	void				*ptr;

	ptr = va_arg(*ap, void*);
	n = (unsigned long long)ptr;
	args->l = count_digits(n);
	value_to_print = get_precision(args, n);
	prefix_postfix = get_width(args);
	if (args->flags.minus)
		res = ft_strjoin(value_to_print, prefix_postfix);
	else
		res = ft_strjoin(prefix_postfix, value_to_print);
	args->l = ft_strlen(res);
	return (res);
}
