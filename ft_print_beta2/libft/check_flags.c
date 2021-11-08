/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <bchytter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 04:49:22 by bchytter          #+#    #+#             */
/*   Updated: 2021/11/08 04:49:22 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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