/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:03:30 by dan               #+#    #+#             */
/*   Updated: 2022/09/30 16:26:33 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
#include <stdlib.h> 

int len_hex(int nb)
{
    int len = 0;
    while (nb != 0)
    {
        nb /= 16;
        len++;
    }
    return (len);
}
char *dec_to_hex_lowercase(int nb)
{
    int i;
    char *str;
    int tmp;
    char base[17] = "0123456789abcdef";
    
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
    int i;
    char *str;
    int tmp;
    char *base;
    base = "0123456789ABCDEF";
    
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
int check_flag1(va_list ap, char c, int i)
{
    
}
int ft_printf(const char *s, ...)
{
    int i = -1;
    va_list ap;
    va_start(ap, s);
    while (s[++i])
    {
        if (s[i] == '%')
        {
            if (s[i + 1] == 's')
            {
                ft_putstr_fd(va_arg(ap, char*), 1);
                i++;
            }
            else if (s[i + 1] == 'd' || s[i + 1] == 'u')
            {
                ft_putnbr_fd(va_arg(ap, int), 1);
                i++;
            }
            else if (s[i + 1] == 'c')
            {
                char c = va_arg(ap, int);
                write(1, &c, 1);
                i++;
            }
            else if (s[i + 1] == '%')
            {
                write(1, "%%", 2);
                i++;
            }
            else if (s[i + 1] == 'x')
            {
                int nb = va_arg(ap, unsigned int);
                ft_putstr_fd(dec_to_hex_lowercase(nb), 1);
                i++;
            }
            else if (s[i + 1] == 'X')
            {
                int nb2 = va_arg(ap, unsigned int);
                ft_putstr_fd(dec_to_hex_uppercase(nb2), 1);
                i++;
            }
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
    //unsigned int nb = 10;
    char c = 'a';
    void *ptr = &c;
    ft_printf("%x %X", 1234, 1234);
    //printf("%lld", 1234);
    return 0;
}