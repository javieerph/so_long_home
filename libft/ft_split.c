/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:08:31 by ejavier-          #+#    #+#             */
/*   Updated: 2025/04/25 08:34:48 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int			word_count(char const *s, char c);
static char			*word(char const *s, char c);
static void			free_array(char **array, int i);
static const char	*skip_delimiters(const char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	array = (char **)ft_calloc((words + 1), sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	while (*s && i < words)
	{
		s = skip_delimiters(s, c);
		array[i] = word(s, c);
		if (!array[i++])
			return (free_array(array, i - 1), NULL);
		while (*s && *s != c)
			s++;
	}
	return (array);
}

static int	word_count(char const *s, char c)
{
	int	count;
	int	word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && word == 0)
		{
			word = 1;
			count++;
		}
		else if (*s == c)
		{
			word = 0;
		}
		s++;
	}
	return (count);
}

static char	*word(char const *s, char c)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)ft_calloc((len + 1), sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	return (word);
}

static void	free_array(char **array, int i)
{
	while (i >= 0)
		free(array[i--]);
	free(array);
}

static const char	*skip_delimiters(const char *s, char c)
{
	while (*s && *s == c)
		s++;
	return (s);
}
