/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:03:30 by dan               #+#    #+#             */
/*   Updated: 2022/10/01 14:36:46 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
#include <stdlib.h> 

long	int	len_hex(unsigned long long nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

char	*dec_to_hex_lowercase(unsigned long long nb)
{
	long int	i;
	char		*str;
	int			tmp;
	char		base[17];

	ft_memcpy(base, "0123456789abcdef", 17);
	i = len_hex(nb) - 1;
	str = malloc(len_hex(nb) + 1);
	if (!str)
		return (NULL);
	while (nb != 0)
	{
		tmp = nb % 16;
		str[i] = base[tmp];
		nb /= 16;
		i--;
	}
	return (str);
}

char *dec_to_hex_uppercase(int nb)
{
	long int	i;
	char		*str;
	int			tmp;
	char		base[17];

	ft_memcpy(base, "0123456789ABCDEF", 17);
	i = len_hex(nb) - 1;
	str = malloc(len_hex(nb) + 1);
	if (!str)
		return (NULL);
	while (nb != 0)
	{
		tmp = nb % 16;
		str[i] = base[tmp];
		nb /= 16;
		i--;
	}
	return (str);
}

int	check_flag1(va_list ap, char c, int i)
{
	char	a;

	if (c == 's')
		ft_putstr_fd(va_arg(ap, char*), 1);
	else if (c == 'd' || c == 'u')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == 'c')
	{
		a = va_arg(ap, int);
		write(1, &a, 1);
	}
	else if (c == '%')
		write(1, "%%", 2);
	else if (c== 'x')
		ft_putstr_fd(dec_to_hex_lowercase(va_arg(ap, unsigned int)), 1);
	else if (c == 'X')
		ft_putstr_fd(dec_to_hex_uppercase(va_arg(ap, unsigned int)), 1);
	else
		return(0);
	return(1);
}

int	check_flag2(va_list ap, char c, int i)
{
	if (c == 'p')
	{
		write(1, "0x", 2);
		ft_putstr_fd(dec_to_hex_lowercase(va_arg(ap, unsigned long long)), 1);
	}
	else
		return(0);
	return(1);
}

int	ft_printf(const char *s, ...)
{
	int	i; 
	va_list	ap;

	i = -1;
	va_start(ap, s);
	while (s[++i])
	{
		if (s[i] == '%')
		{
			if (check_flag1(ap, s[i + 1], i) == 1)
				i++;
			else if (check_flag2(ap, s[i + 1], i) == 1)
				i++;
			else
				write(1, &s[i], 1);
		}
		else
			write(1, &s[i], 1);
	}
	va_end(ap);
	return(0);
}

int main(void)
{
	char c = 'a';
	void *ptr = &c;
	ft_printf("%%");
	return 0;
}