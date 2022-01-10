/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurobert <jurobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:39:19 by jurobert          #+#    #+#             */
/*   Updated: 2021/12/13 02:02:05 by jurobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_type_returns(va_list args, char c);
int		ft_type_char(char c);
int		ft_type_int(int i);
int		ft_type_str(char *s);
int		ft_type_ptr(unsigned long ptr);
int		ft_type_ux(unsigned int u, char *base);
char	*ft_convert_base(size_t n, char *base);

#endif