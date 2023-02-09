/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:18:43 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/02/09 23:57:50 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_nums(char c, va_list *ap, int *len)
{
	int				num;
	char			*s;

	if (c == 117)
		num = va_arg(*ap, unsigned int);
	else
		num = va_arg(*ap, int);
	s = ft_itoa(num);
	*len += ft_strlen(s);
	write(1, s, ft_strlen(s));
	free(s);
	return ;
}

void	handle_string(va_list *ap, int *len)
{
	char	*str;
	int		strlen;

	str = ft_strdup(va_arg(*ap, char *));
	strlen = ft_strlen(str);
	write(1, str, strlen);
	*len += strlen;
	free(str);
	return ;
}

void	handle_hex(const char c, va_list *ap, int *len)
{
	char	*hexstr;
	int		num;
	int		hexlen;

	num = va_arg(*ap, int);
	hexstr = ft_itoh(num);
	hexlen = ft_strlen(hexstr);
	write(1, hexstr, hexlen);
	*len += hexlen;
	free (hexstr);
	return ;
}

int	find_specifier(const char *str, int *len, va_list *ap)
{
	char	*nums;
	char	*hex;
	char	*string;

	nums = "idu";
	hex = "xX";
	string = "sp";

	if (ft_strchr(nums, *str))
		handle_nums(*str, ap, len);
	else if (strchr(hex, *str))
		handle_hex(*str, ap, len);
	else if (strchr(string, *str))
		handle_string(ap, len);
	else if (*str == 37 || *str == 99)
	{
		(*len)++;
		write(1, va_arg(*ap, char), 1);
	}
	else
		return (0);
	return (1);
}
