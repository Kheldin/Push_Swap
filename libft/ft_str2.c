/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:04:27 by kacherch          #+#    #+#             */
/*   Updated: 2025/11/05 17:24:30 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (1)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		if (s[i] == '\0')
			return (0);
		i++;
	}
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	pos;

	pos = -1;
	i = 0;
	while (1)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			pos = i;
		if (s[i] == '\0')
		{
			if (c == '\0')
				return ((char *)&s[pos]);
			break ;
		}
		i++;
	}
	if (pos != -1)
		return ((char *)&s[pos]);
	return (NULL);
}
