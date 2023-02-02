/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:50:39 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/02/03 00:46:17 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"


void	check_flags(const char *str, int *i)
{
	if (str[*i] == 42 || str[*i] == 48)
		justify_content();
	else if (str[*i] == 44 || str[*i] == 32)
		handlesign();
	else if (str[*i] == 46)
		point_flag();
	
	return ;
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;

	if (!str)
		return (0);
	va_start(ap, str);
	i = -1;
	while (str[++i])
	{
		if(str[i] == 37)
			check(str, &i);
		else
			write(1, &str[i], 1);
	}
	write(1, "\n", 1);
	va_end(ap);
	return (0);
}

int	main()
{
	ft_printf("cia%%one");
	return (0);
}