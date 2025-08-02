/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:46:24 by ejavier-          #+#    #+#             */
/*   Updated: 2025/08/02 08:44:56 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	data_type(va_list args, const char data)
{
	int	print_count;

	print_count = 0;
	if (data == 'd' || data == 'i')
		print_count += print_num(va_arg(args, int));
	else if (data == 'c')
		print_count += print_char(va_arg(args, int));
	else if (data == 's')
		print_count += print_str(va_arg(args, char *));
	else if (data == 'p')
		print_count += print_ptr(va_arg(args, void *));
	else if (data == 'u')
		print_count += print_uns(va_arg(args, unsigned int));
	else if (data == 'x')
		print_count += print_hexa(va_arg(args, unsigned int), 0);
	else if (data == 'X')
		print_count += print_hexa(va_arg(args, unsigned int), 1);
	else if (data == '%')
		print_count += print_perc();
	return (print_count);
}
