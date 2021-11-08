/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <bchytter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 09:42:19 by bchytter          #+#    #+#             */
/*   Updated: 2021/11/07 09:42:19 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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