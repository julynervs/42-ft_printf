/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurobert <jurobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:30:02 by jurobert          #+#    #+#             */
/*   Updated: 2021/12/12 22:08:03 by jurobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	if (!str)
		return (0);
	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}
