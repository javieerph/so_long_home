/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 03:20:05 by ejavier-          #+#    #+#             */
/*   Updated: 2025/08/02 08:46:22 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_ptr(void *ptr)
{
	int		len;
	char	*hex_str;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	hex_str = ft_itoa_base((unsigned long)ptr, 16);
	ft_putstr_fd(hex_str, 1);
	len = ft_strlen(hex_str) + 2;
	free(hex_str);
	return (len);
}
