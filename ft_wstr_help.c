/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dezzeddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 20:01:33 by dezzeddi          #+#    #+#             */
/*   Updated: 2018/06/10 20:02:45 by dezzeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t	ft_wcharlen(unsigned wc)
{
	if (wc < 0x80)
		return (1);
	else if (wc < 0x800)
		return (2);
	else if (wc < 0x10000)
		return (3);
	return (4);
}

size_t			ft_wstrlen(unsigned *s)
{
	size_t	len;

	len = 0;
	while (*s != L'\0')
	{
		len += 1;
		++s;
	}
	return (len);
}
