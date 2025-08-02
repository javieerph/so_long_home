/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 05:28:04 by ejavier-          #+#    #+#             */
/*   Updated: 2025/08/02 08:46:12 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hexa(unsigned int num, int uppercase)
{
	int		len;
	char	*hex_str;
	int		i;

	hex_str = ft_itoa_base(num, 16);
	if (uppercase)
	{
		i = 0;
		while (hex_str[i])
		{
			if (hex_str[i] >= 'a' && hex_str[i] <= 'f')
				hex_str[i] -= 32;
			i++;
		}
	}
	ft_putstr_fd(hex_str, 1);
	len = ft_strlen(hex_str);
	free(hex_str);
	return (len);
}
