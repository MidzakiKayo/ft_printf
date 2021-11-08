/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <bchytter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 05:55:53 by bchytter          #+#    #+#             */
/*   Updated: 2021/11/03 05:55:53 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
int ft_printf(const char *format, ...);
int parser_command(char flags, va_list args, size_t data);
int	parser_arg(char c);
size_t	ft_putnbr_base(size_t n, char *base, int base_len, char format);
size_t	ft_putnbr(long n, char *base, int base_len);
int ft_putstr(char *s);
int ft_strlen(char *s);
int len_resault(size_t n);
int	parser_arg(char c);
int parser_command(char flags, va_list args, size_t data);
#endif