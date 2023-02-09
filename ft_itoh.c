/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:34:41 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/02/10 00:18:01 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(int num)
{
	int	counter;

	counter = 0;
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		num = num / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoh(int num)
{
	char	*str;
	int		rest;
	int		numlen;

	if (num == 0)
		return (48);
	rest = 0;
	numlen = ft_numlen(num);
	str = ft_calloc(numlen + 1, 1);
	while (--numlen >= 0)
	{
		rest = num % 16;
		num = num / 16;
		if (rest >= 0 && rest < 10)
			str[numlen] = (char)rest + 48;
		else if (rest > 0 && rest < 16)
			str[numlen] = (char)rest + 55;
 	}
	return (str);
}
