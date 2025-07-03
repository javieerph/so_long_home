/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:48:20 by ejavier-          #+#    #+#             */
/*   Updated: 2025/04/25 02:28:07 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src,
	size_t destsize)
{
	size_t	destlen;
	size_t	srclen;
	size_t	bytes;
	size_t	i;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (destsize <= destlen)
		return (srclen + destsize);
	bytes = destsize - destlen - 1;
	i = 0;
	while (src[i] != '\0' && i < bytes)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
