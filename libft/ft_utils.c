/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:04:52 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/14 18:18:59 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi(const char *nptr)
{
	int		i;
	int		metsign;
	long	sign;
	long	res;

	res = 0;
	sign = 1;
	metsign = 0;
	i = 0;
	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	while (nptr[i] && (nptr[i] == '+' || nptr[i] == '-') && metsign == 0)
	{
		if (nptr[i] == '-')
			sign = -1;
		metsign = 1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}
