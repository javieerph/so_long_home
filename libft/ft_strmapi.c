/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:54:14 by ejavier-          #+#    #+#             */
/*   Updated: 2025/04/25 05:20:57 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned
	int, char))
{
	char	*ret;
	int		i;

	if (!s || !f)
		return (NULL);
	ret = (char *)ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		ret[i] = (*f)(i, *(s + i));
		i++;
	}
	return (ret);
}
