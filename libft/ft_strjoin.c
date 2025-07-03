/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:44:49 by ejavier-          #+#    #+#             */
/*   Updated: 2025/04/25 02:26:57 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *)ft_calloc((len + 1), sizeof(char));
	if (s3 == NULL)
		return (NULL);
	ft_strlcpy(s3, s1, ft_strlen(s1) + 1);
	ft_strlcat(s3, (char *)s2, len + 1);
	return (s3);
}
