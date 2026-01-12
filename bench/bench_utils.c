/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:37:09 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/12 21:46:09 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

static char	*make_res(int len, long nb, char *res, int i)
{
	while (nb > 0)
	{
		if (i == 2)
			res[--len] = '.';
		else
		{
			res[--len] = (nb % 10) + '0';
			nb /= 10;
		}
		i++;
	}
	return (res);
}

char	*ft_itoa_disorder(int n)
{
	char	*res;
	int		len;
	long	nb;
	int		i;

	res = NULL;
	i = 0;
	len = 6;
	if (n == 10000)
	{
		ft_putstr_fd("100.00%", 2);
		return (NULL);
	}
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	nb = n;
	res[len] = '\0';
	res[--len] = '%';
	if (nb == 0)
		res[0] = '0';
	return (make_res(len, nb, res, i));
}
