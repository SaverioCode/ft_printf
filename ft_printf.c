/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:50:39 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/02/09 21:54:18 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	int			len;
	
	if (!str)
		return (0);
	va_start(ap, str);
	len = 0;
	i = -1;
	while (str[++i])
	{
		if(str[i] == 37)
		{
			if (!find_specifier(&(str[++i]), &len, &ap))
				return (len);
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
	}
	va_end(ap);
	return (len);
}
