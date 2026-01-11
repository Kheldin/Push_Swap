/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:24:54 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/11 10:48:38 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

static int	count_digits(int n)
{
	int		count;
	long	nb;

	nb = n;
	count = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		count++;
		nb /= 2;
	}
	return (count);
}

int itoa_binary(int n)
{
	char	*res;
	int		len;
	long	nb;
    size_t size;

	len = count_digits(n);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (-1);
	nb = n;
	res[len] = '\0';
	if (nb == 0)
		res[0] = '0';
	while (nb > 0)
	{
		res[--len] = (nb % 2) + '0';
		nb /= 2;
	}
    size = ft_strlen(res);
    free(res);
    return (size);
}
