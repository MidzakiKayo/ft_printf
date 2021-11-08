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