/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_returns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurobert <jurobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:25:50 by jurobert          #+#    #+#             */
/*   Updated: 2021/12/13 02:45:32 by jurobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "libft/libft.h"

int	ft_type_str(char *s)
{
	if (!s)
		s = "(null)";
	return (write(1, s, ft_strlen(s) * sizeof(char)));
}

int	ft_type_char(char c)
{
	return (write(1, &c, sizeof(c)));
}

int	ft_type_int(int i)
{
	char	*s;
	int		len;

	s = ft_itoa(i);
	len = ft_strlen(s);
	write(1, s, len * sizeof(char));
	free(s);
	s = NULL;
	return (len);
}

int	ft_type_ux(unsigned int u, char *base)
{
	char	*s;
	int		len;

	s = ft_convert_base(u, base);
	len = ft_strlen(s);
	write(1, s, len * sizeof(char));
	free(s);
	s = NULL;
	return (len);
}

int	ft_type_ptr(unsigned long ptr)
{
	char	*s;
	char	*aux;
	int		len;

	if (ptr == 0)
	{
		s = "(nil)";
		len = write(1, s, ft_strlen(s) * sizeof(char));
	}
	else
	{
		s = ft_convert_base(ptr, "0123456789abcdef");
		aux = s;
		s = ft_strjoin("0x", aux);
		free(aux);
		len = write(1, s, ft_strlen(s) * sizeof(char));
		free(s);
		s = NULL;
	}
	return (len);
}
