/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:37:37 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/02/09 21:29:49 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_revstr(const char *s)
{
	char	*revstr;
	int		slen;
	int		i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	revstr = ft_calloc(slen + 1, 1);
	if (!revstr)
		return (NULL);
	i = -1;
	while (++i < slen)
		revstr[i] = s[slen - i - 1];
	return (revstr);
}

char	*ft_itoa(int n)
{
	int		strlen;
	char	temp[12];
	int		num;
	int		i;

	i = -1;
	strlen = 0;
	num = n;
	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		num = -num;
	while (num > 0)
	{
		temp[++i] = (num % 10) + 48;
		num = (num - (num % 10)) / 10;
	}
	if (n < 0)
		temp[++i] = '-';
	temp[++i] = 0;
	return (ft_revstr(temp));
}
