/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <bchytter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 05:47:41 by bchytter          #+#    #+#             */
/*   Updated: 2021/11/03 05:47:41 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
char *DIGIT_int = "0123456789";
char *DIGIT_16intl = "0123456789abcdef";
char *DIGIT_16intu = "0123456789ABCDEF";

int	check_flags(char c)
{
	char *flags;

	flags = "cspdiuxX%";
	while(*flags != '\0')
	{
		if (*flags == c)
			return (1);
		flags++;
	}
	return (0);
}

int ft_putstr(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	parser_arg(char c)
{
	char *int_flag;
	char *uint_flag;
	
	int_flag = "cdi";
	uint_flag = "uxX";
	while(*int_flag != '\0')
	{
		if (*int_flag == c)
			return (1);
		int_flag++;
	}
	while(*uint_flag != '\0')
	{
		if (*uint_flag == c)
			return (2);
		uint_flag++;
	}
	return (0);
}

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		s[i++];
	return (i);
}

size_t	ft_putnbr_base(size_t n, char *base, int base_len, char format)
{
	int		len;
	int		i;
	char	str[30];

	i = 0;
	len = 0;
	if (parser_arg(format) == 2)
		n = (unsigned int) n;
	if (n == 0)
	{
		str[0] = '0';
		return (write(1, &str[0], 1));
	}
	while (n != 0)
	{
		str[i++] = base[n % base_len];
		n /= base_len;
		len++;
	}
	while (i--)
		write(1, &str[i], 1);
	return (len);
}

size_t	ft_putnbr(long n, char *base, int base_len)
{
	int		len;
	int		i;
	char	str[30];

	i = 0;
	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		len++;
	}
	if (n == 0)
	{
		str[0] = '0';
		return (write(1, &str[0], 1));
	}
	while (n != 0)
	{
		str[i++] = base[n % base_len];
		n /= base_len;
		len++;
	}
	while (i--)
		write(1, &str[i], 1);
	return (len);
}

int parser_command(char flags, va_list args, size_t data)
{
	if (flags == 'c')
	{
		return(write(1, &(data), 1));
	}
	else if (flags == 'i' || flags == 'd')
	{
		return (ft_putnbr(data, DIGIT_int, 10));
	}
	else if (flags == 'u')
	{
		return (ft_putnbr_base(data, DIGIT_int, 10, 'u'));
	}
	else if (flags == 'x')
	{
		return (ft_putnbr_base(data, DIGIT_16intl, 16, 'x'));
	}
	else if (flags == 'X')
	{
		return (ft_putnbr_base(data, DIGIT_16intu, 16, 'X'));
	}
	else if (flags == 'p')
	{
		write(1, "0x", 2);
		return (ft_putnbr_base(va_arg(args, size_t), DIGIT_16intl, 16, 'p') + 2);
	}
	else if (flags == 's')
	{
		return (ft_putstr(va_arg(args, char *)));
	}
	else
	{
		return (write(1, "%", 1));
	}
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	int len;
	char *str;
	int i;
	size_t data;

	len = 0;
	data = 0;
	i = 0;
	str = (char *)format;
	va_start(ap, format);
	while (str[i] != '\0')
	{
		if(str[i] == '%' && check_flags(str[i++]))
		{
			if (parser_arg(str[i]) == 1)
			{
				data = va_arg(ap, int);
			}
			else if (parser_arg(str[i]) == 2)
			{
				data = va_arg(ap, unsigned int);
			}
			len += parser_command(str[i], ap, data);
			i++;
		}
		else
			len += write(1, &str[i++], 1);
	}
	va_end(ap);
	return (len);
}