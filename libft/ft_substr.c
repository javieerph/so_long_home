/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:01:49 by ejavier-          #+#    #+#             */
/*   Updated: 2025/04/25 05:55:53 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start,
	size_t len)
{
	size_t	i;
	char	*substr;

	if (len == 0 || !s)
		return (ft_strdup(""));
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if ((len > ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	i = 0;
	substr = (char *)ft_calloc((len + 1), sizeof(char));
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	return (substr);
}
