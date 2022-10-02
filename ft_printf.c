/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:03:30 by dan               #+#    #+#             */
/*   Updated: 2022/10/02 16:52:29 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	ft_printf(const char *s, ...)
{
	int		count;
	int		i;
	va_list	ap;

	count = 0;
	i = -1;
	va_start(ap, s);
	while (s[++i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			count = check_flags(ap, s[i + 1], count);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}
/*
int	main(void)
{
	ft_printf("%d", ft_printf(" %x ", 0));
	write(1, "\n", 1);
	return (0);
}*/
