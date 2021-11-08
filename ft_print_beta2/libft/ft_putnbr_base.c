/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <bchytter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 09:38:44 by bchytter          #+#    #+#             */
/*   Updated: 2021/11/07 09:38:44 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_base(size_t n, char *base, int base_len, char format)
{
	int		len;
	int		i;
	char	str[40];

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
	str[len] = '\0';
	while (i--)
		write(1, &str[i], 1);
	return (len);
}