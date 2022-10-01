/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:19:51 by dan               #+#    #+#             */
/*   Updated: 2022/10/01 14:31:01 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    char *dest2 = dest;
    const char *src2 = src;

    size_t i = 0;
    while (i < n)
    {
        dest2[i] = src2[i];
        i++;
    }
    return (dest2);
}