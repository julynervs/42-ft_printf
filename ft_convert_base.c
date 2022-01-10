/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurobert <jurobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:05:24 by jurobert          #+#    #+#             */
/*   Updated: 2021/12/13 02:21:09 by jurobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

char	*ft_convert_base(size_t n, char *base)
{
	size_t	base_len;
	int		str_base_len;
	size_t	aux;
	char	*str_base;

	base_len = ft_strlen(base);
	str_base_len = 0;
	aux = n;
	if (n == 0)
		str_base_len = 1;
	while (aux != 0)
	{
		aux /= base_len;
		str_base_len++;
	}
	str_base = (char *)malloc((str_base_len + 1) * sizeof(char));
	if (!str_base)
		return (NULL);
	str_base[str_base_len] = '\0';
	while (str_base_len--)
	{
		str_base[str_base_len] = base[n % base_len];
		n /= base_len;
	}
	return (str_base);
}
