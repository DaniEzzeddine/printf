/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dezzeddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:06:36 by dezzeddi          #+#    #+#             */
/*   Updated: 2018/06/06 21:24:01 by dezzeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_flags
{
	int				minus;
	int				plus;
	int				space;
	int				hashtag;
	int				zero;
}					t_flags;

typedef struct		s_param
{
	int				dot;
	char			specifier;
	t_flags			flags;
	int				width;
	int				precision;
	char			*length;
	int				l;
}					t_param;

typedef char		*(*t_func)(t_param*, va_list*);

char				*ft_handle_wstr(t_param *args, va_list *ap);
char				*ft_handle_binary(t_param *args, va_list *ap);
char				*ft_handle_addr(t_param *args, va_list *ap);
char				*ft_handle_octal(t_param *args, va_list *ap);
char				*ft_handle_hex(t_param *args, va_list *ap);
char				*ft_handle_char(t_param *args, va_list *ap);
char				*ft_handle_uint(t_param *args, va_list *ap);
char				*ft_handle_str(t_param *arg, va_list *ap);
char				*ft_handle_int(t_param *args, va_list *ap);
size_t				ft_wstrlen(unsigned *s);
int					ft_algo(t_param *arg, va_list *ap);
t_func				get_func(char c);
char				*parse_length(char *format, size_t *i);
int					parse_precision(char *fmt, size_t *i,
					va_list *ap, t_param *specif);
int					parse_width(char *fmt, size_t *i,
					va_list *ap, t_param *specif);
t_flags				parse_flags(char *format, size_t *i);
t_param				*parse_params(char *format, va_list *ap, size_t *i);
void				ft_remalloc(void *src, size_t *size);
int					ft_printf(char *format, ...);
size_t				size_of_final_str(char *format, va_list *ap);
long long			convert(t_param *arg, va_list *ap);
unsigned long long	convert_u(t_param *arg, va_list *ap);
size_t				ft_wcslen(const wchar_t *s);

#endif
