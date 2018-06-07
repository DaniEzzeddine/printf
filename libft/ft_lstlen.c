/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dezzeddi <dezzeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 09:05:02 by dezzeddi          #+#    #+#             */
/*   Updated: 2017/06/30 09:08:22 by dezzeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstlen(t_list *list)
{
	int	i;

	i = 0;
	if (!list)
		return (0);
	while (list->next)
	{
		list = list->next;
		i++;
	}
	return (i + 1);
}
