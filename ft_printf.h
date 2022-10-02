/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:29:08 by dan               #+#    #+#             */
/*   Updated: 2022/10/02 17:43:24 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*dec_to_hex_lowercase(unsigned long long nb);
long	int	len_hex(unsigned long long nb);
char	*dec_to_hex_uppercase(unsigned long long nb);
int		check_flags(va_list ap, char c, int count);
int		check_flag3(va_list ap, char c, int count);
int		check_flag2(va_list ap, char c, int count);
int		check_flag1(va_list ap, char c, int count);
int		check_flag4(va_list ap, char c, int count);
int		check_flag0(va_list ap, char c, int count);
void	ft_putunbr_fd(unsigned int n, int fd);

#endif