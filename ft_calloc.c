/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 05:28:30 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/02/09 21:47:50 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*p;
	char	*t;

	i = 0;
	if ((count > 2147483424 || size > 2147483424))
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	t = (char *)p;
	while (i < count * size)
		t[i++] = 0;
	return (p);
}
