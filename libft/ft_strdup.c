/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 09:58:23 by ejavier-          #+#    #+#             */
/*   Updated: 2025/04/25 02:19:15 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*cpy;

	len = ft_strlen(s);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (cpy == NULL)
		return (NULL);
	ft_strlcpy(cpy, s, len + 1);
	return (cpy);
}
