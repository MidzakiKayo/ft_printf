/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <bchytter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 09:44:34 by bchytter          #+#    #+#             */
/*   Updated: 2021/11/07 09:44:34 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int parser_command(char flags, va_list args, size_t data)
{
    char *DIGIT_int;
    char *DIGIT_16intl;
    char *DIGIT_16intu;

    DIGIT_int = "0123456789";
    DIGIT_16intl = "0123456789abcdef";
    DIGIT_16intu = "0123456789ABCDEF";
	if (flags == 'c')
		return(write(1, &(data), 1));
	else if (flags == 'i' || flags == 'd')
		return (ft_putnbr(data, DIGIT_int, 10));
	else if (flags == 'u')
		return (ft_putnbr_base(data, DIGIT_int, 10, 'u'));
	else if (flags == 'x')
		return (ft_putnbr_base(data, DIGIT_16intl, 16, 'x'));
	else if (flags == 'X')
		return (ft_putnbr_base(data, DIGIT_16intu, 16, 'X'));
	else if (flags == 'p')
	{
		write(1, "0x", 2);
		return (ft_putnbr_base(va_arg(args, size_t), DIGIT_16intl, 16, 'p') + 2);
	}
	else if (flags == 's')
		return (ft_putstr(va_arg(args, char *)));
	else
		return (write(1, "%", 1));
}