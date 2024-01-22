/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febasma <febasma@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:52:58 by febasma           #+#    #+#             */
/*   Updated: 2024/01/22 15:55:53 by febasma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			count += ft_format(*(++str), ap);
		else 
			ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	int count;

	count = 0;
	count = ft_printf("hello %%, %s  ", "world");
	printf("%d", count);
	return (0);
}