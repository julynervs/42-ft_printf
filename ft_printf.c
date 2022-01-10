/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurobert <jurobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:25:39 by jurobert          #+#    #+#             */
/*   Updated: 2021/12/13 01:43:58 by jurobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

static int	ft_type(va_list args, char c)
{
	if (c == 'c')
		return (ft_type_char(va_arg(args, int)));
	else if (c == 's')
		return (ft_type_str(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_type_ptr(va_arg(args, unsigned long)));
	else if (c == 'd' || c == 'i')
		return (ft_type_int(va_arg(args, int)));
	else if (c == 'u')
		return (ft_type_ux(va_arg(args, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_type_ux(va_arg(args, unsigned long), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_type_ux(va_arg(args, unsigned long), "0123456789ABCDEF"));
	else if (c == '%')
		return (write(1, "%", 1));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_type(args, str[i]);
		}
		else
			len += ft_type_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
