/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:26:24 by ejavier-          #+#    #+#             */
/*   Updated: 2025/04/25 08:41:39 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (ft_strlen(src));
}
