/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:03:58 by kacherch          #+#    #+#             */
/*   Updated: 2025/11/06 12:55:06 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i] && !(s[i] == c))
		{
			count++;
			while (s[i] && !(s[i] == c))
				i++;
		}
	}
	return (count);
}

static char	*ft_worddup(char const *str, int start, int end)
{
	int		i;
	char	*word;

	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static int	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (1);
}

static int	ft_fill_split(char **res, char const *s, char c)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i] && !(s[i] == c))
		{
			start = i;
			while (s[i] && !(s[i] == c))
				i++;
			if (i > start)
			{
				res[j++] = ft_worddup(s, start, i);
				if (!res[j - 1])
					return (ft_free_split(res));
			}
		}
	}
	res[j] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	res = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	if (ft_fill_split(res, s, c))
		return (NULL);
	return (res);
}
