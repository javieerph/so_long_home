/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:39:30 by ejavier-          #+#    #+#             */
/*   Updated: 2025/04/25 10:58:27 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ptr;

	if (elsize != 0 && nelem > SIZE_MAX / elsize)
		return (NULL);
	ptr = malloc(nelem * elsize);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (nelem * elsize));
	return (ptr);
}
