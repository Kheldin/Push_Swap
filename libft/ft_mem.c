/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:05:15 by kacherch          #+#    #+#             */
/*   Updated: 2025/11/03 16:12:16 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n)
	{
		*ptr = (unsigned char)c;
		ptr++;
		n--;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*src_ptr;
	unsigned char	*dest_ptr;

	if (!dest && !src)
		return (NULL);
	src_ptr = (unsigned char *)src;
	dest_ptr = (unsigned char *)dest;
	while (n)
	{
		*dest_ptr = *src_ptr;
		dest_ptr++;
		src_ptr++;
		n--;
	}
	return (dest);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr_s;
	size_t			i;

	i = 0;
	ptr_s = (unsigned char *)s;
	while (i < n)
	{
		if (ptr_s[i] == (unsigned char)c)
			return (&ptr_s[i]);
		i++;
	}
	return (NULL);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	if (!dest && !src)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	src_ptr = (unsigned char *)src;
	dest_ptr = (unsigned char *)dest;
	if (dest < src)
	{
		while (n--)
			*(dest_ptr++) = *src_ptr++;
	}
	else
	{
		dest_ptr += n;
		src_ptr += n;
		while (n--)
			*(--dest_ptr) = *(--src_ptr);
	}
	return (dest);
}
