/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:03:48 by kacherch          #+#    #+#             */
/*   Updated: 2025/11/03 16:11:44 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int	count_digits(int n)
{
	int		count;
	long	nb;

	nb = n;
	count = 0;
	if (nb == 0)
		return (1);
	if (n < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb > 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	nb;

	len = count_digits(n);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	nb = n;
	res[len] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		res[0] = '0';
	while (nb > 0)
	{
		res[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (res);
}
