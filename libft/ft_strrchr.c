/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:56:37 by ejavier-          #+#    #+#             */
/*   Updated: 2025/04/25 05:14:27 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	int		i;

	last = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			last = (char *)(s + i);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)(s + i));
	}
	else
	{
		return (last);
	}
}
