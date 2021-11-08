/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <bchytter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 09:39:53 by bchytter          #+#    #+#             */
/*   Updated: 2021/11/07 09:39:53 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr(long n, char *base, int base_len)
{
	int		len;
	int		i;
	char	str[40];

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
		return (write(1, base, 1));
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